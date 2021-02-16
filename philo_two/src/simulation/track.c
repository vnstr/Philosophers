/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:41:57 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/06 20:41:57 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "table_initiation.h"
#include "simulation.h"
#include "utils.h"

int		check_death(t_philo *philo)
{
	return (get_sim_mstime(*philo->start_sim_time)
			- philo->last_eating_time
			> (uint64_t)*philo->time_to_die + 5);
}

int		check_each_eated(t_tracking *tracking)
{
	t_philo		*philos;
	uint64_t	amount_eaten;
	int			amount_philos;
	int			nb_of_must_eat;
	int			i;

	philos = tracking->philos;
	amount_eaten = 0;
	amount_philos = tracking->args->nb_of_philos;
	nb_of_must_eat = tracking->args->nb_of_must_eat;
	i = 0;
	while (i < amount_philos)
	{
		amount_eaten += philos[i].eating_counter;
		i += 1;
	}
	if (amount_eaten >= (uint64_t)(nb_of_must_eat * amount_philos))
		return (1);
	return (0);
}

void	check_philos_death_or_each_eated(t_tracking *tracking)
{
	t_philo		*philos;
	int			i;

	philos = tracking->philos;
	i = 0;
	while (i < tracking->args->nb_of_philos)
	{
		if (check_death(&philos[i]))
		{
			philos[i].time_of_death = get_sim_mstime(*philos[i].start_sim_time);
			get_dying(&philos[i]);
			break ;
		}
		if (tracking->args->nb_of_must_eat != 0 && check_each_eated(tracking))
		{
			sem_wait(philos->saying);
			*tracking->each_eated_f = 1;
			sem_post(philos->saying);
		}
		i += 1;
	}
}

void	*track(void *tracking_arg)
{
	t_tracking	*tracking;

	tracking = (t_tracking*)tracking_arg;
	while (*tracking->someone_dead_f == 0 && *tracking->each_eated_f == 0)
		check_philos_death_or_each_eated(tracking);
	return (NULL);
}
