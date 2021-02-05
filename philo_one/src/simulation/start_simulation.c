/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:54:40 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/05 13:54:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "table_initiation.h"

void	*live(void *philo_arg)
{
	t_philo		*philo;

	philo = (t_philo*)philo_arg;
	pthread_mutex_lock(philo->saying);
	write(1, philo->msgs->eating, ft_strlen(philo->msgs->eating));
	pthread_mutex_unlock(philo->saying);
	return (NULL);
}

int		start_simulation(t_table *table)
{
	t_philo		*philos;
	uint32_t	i;

	philos = table->philos;
	i = 0;
	while (i < table->args->nb_of_philos)
	{
		if (pthread_create(&(philos[i].philo), NULL, live, (void*)&(philos[i])) != 0)
		{
			write(2, "Error: can't create thread\n", 28);
			return (1);
		}
		i += 1;
	}
	int	join_status = 0;
	i = 0;
	while (i < table->args->nb_of_philos)
	{
		if (pthread_join(philos[i].philo, (void**)&join_status) != 0)
		{
			write(2, "Error: can't join thread\n", 26);
			return (1);
		}
		printf("join_status = |%d|\n", join_status);
		i += 1;
	}
	return (0);
}
