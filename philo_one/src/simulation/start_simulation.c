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
	t_tracking	*trackings;
	uint32_t	amount;
	uint32_t	i;
	uint32_t	j;

	amount = table->args->nb_of_philos;
	philos = table->philos;
	trackings = table->trackings;
	i = 0;
	j = 0;
	table->start_sim_time = get_mstime();
	while (i < amount)
	{
		if (pthread_create(&philos[i].thread, NULL, live, (void*)&philos[i]))
		{
			ft_putstr_fd(CREATE_THREAD_ERROR, 2);
			return (i + j);
		}
		if (pthread_create(&trackings[j].thread, NULL, track, (void*)&trackings[j]))
		{
			ft_putstr_fd(CREATE_THREAD_ERROR, 2);
			return (i + j);
		}
		i += 1;
		j += 1;
	}
	return (i + j);
}

static uint32_t		join_threads(t_table *table)
{
	t_philo		*philos;
	t_tracking	*trackings;
	uint32_t	amount;
	uint32_t	i;
	uint32_t	j;

	amount = table->args->nb_of_philos;
	philos = table->philos;
	trackings = table->trackings;
	i = 0;
	j = 0;
	while (i < amount)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			ft_putstr_fd(JOIN_THREAD_ERROR, 2);
			return (i + j);
		}
		if (pthread_join(trackings[j].thread, NULL))
		{
			ft_putstr_fd(JOIN_THREAD_ERROR, 2);
			return (i + j);
		}
		i += 1;
		j += 1;
	}
	return (i + j);
}

int					start_simulation(t_table *table)
{
	uint32_t	nb_of_philo_threads;
	uint32_t	nb_of_track_threads;

	nb_of_philo_threads = table->args->nb_of_philos;
	nb_of_track_threads = table->trackings_amount;

	if (create_threads(table) != nb_of_philo_threads + nb_of_track_threads)
		return (1);
	if (join_threads(table) != nb_of_philo_threads + nb_of_track_threads)
		return (1);
	return (0);
}
