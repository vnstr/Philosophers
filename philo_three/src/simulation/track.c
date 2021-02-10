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
			>= (uint64_t)*philo->time_to_die);
}

int		check_each_eated(t_tracking *tracking)
{
	t_philo		*philo;
	uint64_t	amount_eaten;
	int			amount_philos;
	int			nb_of_must_eat;
	int			i;

	philo = tracking->philo;
	amount_eaten = 0;
	amount_philos = tracking->args->nb_of_philos;
	nb_of_must_eat = tracking->args->nb_of_must_eat;
	i = 0;
	return (0);
}

void	check_philos_death_or_each_eated(t_tracking *tracking)
{
	t_philo		*philo;
	int			i;

	philo = tracking->philo;
	i = 0;
	/*
	if (check_death(philo))
	{
		philo->time_of_death = get_sim_mstime(*philo->start_sim_time);
		get_dying(philo);
	}
	*/
	//if (tracking->args->nb_of_must_eat != 0 && check_each_eated(tracking))
		//*tracking->each_eated_f = 1;
	i += 1;
}

#include <stdio.h>

void	*track(void *tracking_arg)
{
	t_tracking	*tracking;

	//printf("tracking_arg_p = |%p|\n", tracking_arg);
	tracking = (t_tracking*)tracking_arg;
	printf("tracking->philo->id = |%d|\n", tracking->philo->id);
	/*
	while (*tracking->someone_dead_f == 0 && *tracking->each_eated_f == 0)
		check_philos_death_or_each_eated(tracking);
		*/
	//sleep(10);
	return (NULL);
}
