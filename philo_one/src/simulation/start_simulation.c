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

#include "libft.h"
#include "simulation.h"
#include "table_initiation.h"
#include "utils.h"

static uint32_t		create_threads(t_table *table)
{
	t_philo		*philos;
	uint32_t	amount;
	uint32_t	i;

	amount = table->args->nb_of_philos;
	philos = table->philos;
	i = 0;
	table->start_sim_time = get_time();
	while (i < amount)
	{
		if (pthread_create(&philos[i].thread, NULL, live, (void*)&philos[i]))
		{
			ft_putstr_fd(CREATE_THREAD_ERROR, 2);
			return (i);
		}
		i += 1;
	}
	return (i);
}

static uint32_t	join_threads(t_table *table)
{
	t_philo		*philos;
	uint32_t	amount;
	uint32_t	i;

	amount = table->args->nb_of_philos;
	philos = table->philos;
	i = 0;
	while (i < amount)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			ft_putstr_fd(JOIN_THREAD_ERROR, 2);
			return (i);
		}
		i += 1;
	}
	return (i);
}

int				start_simulation(t_table *table)
{
	uint32_t	nb_of_threads;

	nb_of_threads = table->args->nb_of_philos;
	if (create_threads(table) != nb_of_threads)
		return (1);
	if (join_threads(table) != nb_of_threads)
		return (1);
	return (0);
}
