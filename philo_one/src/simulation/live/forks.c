/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:39:02 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 14:39:03 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_initiation.h"
#include "saying.h"

void	get_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return ;
	}
	say_taking_fork(philo);
	pthread_mutex_unlock(philo->saying);
}

void	get_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	pthread_mutex_lock(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		pthread_mutex_unlock(philo->saying);
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return ;
	}
	say_taking_fork(philo);
	pthread_mutex_unlock(philo->saying);
}

void	get_forks(t_philo *philo)
{
	get_left_fork(philo);
	get_right_fork(philo);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}
