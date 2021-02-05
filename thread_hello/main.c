/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:30:19 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/03 15:30:21 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include <pthread.h>

#define SUCCESS 0
#define ERROR ((void*)(-1))

typedef struct		s_str
{
	int				id;
	char			*s;
	int				len;
}					t_str;

#include <string.h>

void	*ft_strlen(void *args)
{
	t_str	*str;

	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %d\n",
	current_time.tv_sec, current_time.tv_usec);
	str = (t_str*)args;
	if (str->s == NULL)
	{
		str->len = 0;
		return (ERROR);
	}
	printf("%s\n", str->s);
	str->len = strlen(str->s);
	return (SUCCESS);
}

int		main(void)
{

	/*
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	printf("seconds : %ld\nmicro seconds : %d\n",
	current_time.tv_sec, current_time.tv_usec);
	*/






	pthread_t	threads[4];
	char	*msgs[] = {"First", NULL, "Third", "Fourth"};
	t_str		args[4];
	int			status;
	int			status_addr;

	for (int i = 0; i < 4; i += 1)
	{
		args[i].id = i;
		args[i].s = msgs[i];
	}
	for (int i = 0; i < 4; i += 1)
	{
		status = pthread_create(&threads[i], NULL, ft_strlen, &args[i]);
		if (status != 0)
		{
			write(2, "Error: can't create thread\n", 28);
			return (1);
		}
	}
	printf("Hello from main\n");
	for (int i = 0; i < 4; i += 1)
	{
		status = pthread_join(threads[i], (void**)&status_addr);
		if (status != 0)
		{
			write(2, "Error: can't join thread\n", 26);
			return (1);
		}
		printf("joined with address %d\n", status_addr);
	}
	return (0);
}
