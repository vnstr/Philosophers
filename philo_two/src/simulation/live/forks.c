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

#include <unistd.h>

#include "table_initiation.h"
#include "saying.h"

static int	get_fork(t_philo *philo)
{
	sem_wait(philo->forks->sem);
	sem_wait(philo->saying);
	usleep(180);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		sem_post(philo->forks->sem);
		sem_post(philo->saying);
		return (1);
	}
	say_taking_fork(philo);
	sem_post(philo->saying);
	return (0);
}

void		put_forks(t_philo *philo)
{
	sem_post(philo->forks->sem);
	sem_post(philo->forks->sem);
}

int			get_forks(t_philo *philo)
{
	if (get_fork(philo) != 0)
		return (1);
	if (get_fork(philo) != 0)
		return (1);
	return (0);
}
