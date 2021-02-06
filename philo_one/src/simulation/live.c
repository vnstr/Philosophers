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
#include "saying.h"
#include "utils.h"

void	get_dying(t_philo *philo)
{
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0)
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
	if (*philo->someone_dead_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_sleeping(philo);
	pthread_mutex_unlock(philo->saying);
	usleep(*philo->time_to_sleep * 1000);
}

void	get_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_thinking(philo);
	pthread_mutex_unlock(philo->saying);
}

void	get_eating(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	pthread_mutex_lock(&(philo->right_fork->mutex));
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0)
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		pthread_mutex_unlock(philo->saying);
		return ;
	}
	say_eating(philo);
	pthread_mutex_unlock(philo->saying);
	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	usleep(*philo->time_to_eat * 1000);
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	*live(void *philo_arg)
{
	t_philo		*philo;

	philo = (t_philo*)philo_arg;
	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	while (*philo->someone_dead_f == 0)
	{
		get_sleeping(philo);
		get_thinking(philo);
		get_eating(philo);
	}
	return (NULL);
}
