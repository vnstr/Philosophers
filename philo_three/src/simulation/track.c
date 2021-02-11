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
#include <stdio.h>

#include "table_initiation.h"
#include "simulation.h"
#include "utils.h"

int		check_death(t_philo *philo)
{
	return ((int64_t)get_sim_mstime(*philo->start_sim_time)
			- (int64_t)philo->last_eating_time
			> (int64_t)*philo->time_to_die);
}

void	check_philos_death_or_each_eated(t_tracking *tracking)
{
	t_philo		*philo;
	int			i;

	philo = tracking->philo;
	if (check_death(philo))
	{
		philo->time_of_death = get_sim_mstime(*philo->start_sim_time);
		get_dying(philo);
		sem_post(tracking->someone_dead_sem);
	}
}

#include <stdio.h>

void	*track(void *tracking_arg)
{
	t_tracking	*tracking;

	tracking = (t_tracking*)tracking_arg;
	while (*tracking->someone_dead_f == 0 && *tracking->each_eated_f == 0)
		check_philos_death_or_each_eated(tracking);
	return (NULL);
}
