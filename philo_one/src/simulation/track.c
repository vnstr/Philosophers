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

#include "table_initiation.h"
#include "simulation.h"
#include "utils.h"

int		check_death(t_philo *philo)
{
	return (get_sim_mstime(*philo->start_sim_time) - philo->last_eating_time >=  (uint64_t)*philo->time_to_die);
}

void	check_philos_death(t_tracking *tracking)
{
	t_philo		*philos;
	uint32_t	i;

	philos = tracking->philos;
	i = 0;
	while (i < tracking->args->nb_of_philos)
	{
		if (check_death(&philos[i]))
		{
			get_dying(&philos[i]);
			break ;
		}
		i += 1;
	}
}

void	*track(void *tracking_arg)
{
	t_tracking	*tracking;

	tracking = (t_tracking*)tracking_arg;
	while (*tracking->someone_dead_f == 0)
		check_philos_death(tracking);
	return (NULL);
}
