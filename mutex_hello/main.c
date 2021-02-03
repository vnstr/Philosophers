/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:56:07 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/03 16:56:12 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define SUCCESS 0

static int		counter;
pthread_mutex_t	mutex;

void	*plus_one(void *args)
{
	int	local;

	pthread_mutex_lock(&mutex);
	local = counter;
	printf("counter += 1\n");
	local += 1;
	counter = local;
	pthread_mutex_unlock(&mutex);
	return (SUCCESS);
}

void	*minus_one(void *args)
{
	int	local;

	pthread_mutex_lock(&mutex);
	local = counter;
	printf("counter -= 1\n");
	local -= 1;
	counter = local;
	pthread_mutex_unlock(&mutex);
	return (SUCCESS);
}

#define NUM_OF_THREADS 4

int		main(void)
{
	pthread_t	threads[NUM_OF_THREADS];
	int	status;
	int	status_addr;
	int	i;

	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		write(2, "Error: can't init mutex\n", 25);
		exit(1);
	}
	i = 0;
	while (i < NUM_OF_THREADS / 2)
	{
		status = pthread_create(&threads[i], NULL, plus_one, NULL);
		if (status != 0)
		{
			write(2, "Error: can't create thread\n", 28);
			exit(1);
		}
		i += 1;
	}
	while (i < NUM_OF_THREADS)
	{
		status = pthread_create(&threads[i], NULL, minus_one, NULL);
		if (status != 0)
		{
			write(2, "Error: can't create thread\n", 28);
			exit(1);
		}
		i += 1;
	}
	i = 0;
	while (i < NUM_OF_THREADS)
	{
		status = pthread_join(threads[i], (void**)&status_addr);
		if (status != 0)
		{
			write(2, "Error: can't join thread\n", 26);
			exit(1);
		}
		printf("counter = |%d|\n", counter);
		i += 1;
	}
	if (pthread_mutex_destroy(&mutex) != 0)
	{
		write(2, "Error: can't destroy mutex\n", 28);
		exit(1);
	}
	return (SUCCESS);
}
