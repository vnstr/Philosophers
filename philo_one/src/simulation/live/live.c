/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:28:39 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/06 17:28:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

#include "libft.h"
#include "table_initiation.h"
#include "forks.h"
#include "saying.h"
#include "utils.h"

void	get_dying(t_philo *philo)
{
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_dying(philo);
	*philo->someone_dead_f = 1;
	pthread_mutex_unlock(philo->saying);
}

void	get_sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_sleeping(philo);
	pthread_mutex_unlock(philo->saying);
	ft_mssleep(*philo->time_to_sleep);
}

void	get_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_thinking(philo);
	pthread_mutex_unlock(philo->saying);
}

void	get_eating(t_philo *philo)
{
	get_forks(philo);
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		put_forks(philo);
		return ;
	}
	say_eating(philo);
	pthread_mutex_unlock(philo->saying);

	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	philo->eating_counter += 1;
	ft_mssleep(*philo->time_to_eat);

	put_forks(philo);
}

void	*live(void *philo_arg)
{
	t_philo		*philo;
	uint8_t		*someone_dead_f;
	uint8_t		*each_eated_f;

	philo = (t_philo*)philo_arg;
	someone_dead_f = philo->someone_dead_f;
	each_eated_f = philo->each_eated_f;
	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	while (*someone_dead_f == 0 && *each_eated_f == 0)
	{
		get_sleeping(philo);
		get_thinking(philo);
		get_eating(philo);
	}
	return (NULL);
}
