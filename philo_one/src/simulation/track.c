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
	return (get_sim_mstime(*philo->start_sim_time) - philo->last_eating_time >=  (uint64_t)*philo->time_to_die);
}

int		check_each_eated(t_tracking *tracking)
{
	t_philo		*philos;
	uint64_t	amount_eaten;
	uint32_t	amount_philos_for_check;
	uint32_t	i;

	philos = tracking->philos;
	amount_eaten = 0;
	if (tracking->args->nb_of_philos <= 4)
	i = 0;
	while (i < tracking->args->nb_of_philos)
	{
		amount_eaten += philos[i].eating_counter;
		i += 1;
	}
	if (amount_eaten >= tracking->args->nb_of_must_eat)
		return (1);
	else
		return (0);


}

void	check_philos_death_or_each_eated(t_tracking *tracking)
{
	t_philo		*philos;
	uint32_t	i;

	philos = tracking->philos;
	i = 0;
	while (i < tracking->args->nb_of_philos && i < 1)
	{
		if (check_death(&philos[i]))
		{
			get_dying(&philos[i]);
			break ;
		}
		if (tracking->args->nb_of_must_eat != 0 && check_each_eated(tracking))
		{
			pthread_mutex_lock(tracking->each_eated_f_mutex);
			*tracking->each_eated_f = 1;
			pthread_mutex_unlock(tracking->each_eated_f_mutex);
			break ;
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
