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

#include "table_initiation.h"
#include "forks.h"
#include "saying.h"
#include "utils.h"

void		get_dying(t_philo *philo)
{
	sem_wait(philo->saying);
	say_dying(philo);
}

static void	get_sleeping(t_philo *philo)
{
	sem_wait(philo->saying);
	say_sleeping(philo);
	sem_post(philo->saying);
	ft_mssleep(*philo->time_to_sleep, philo);
}

static void	get_thinking(t_philo *philo)
{
	sem_wait(philo->saying);
	say_thinking(philo);
	sem_post(philo->saying);
}

static void	get_eating(t_philo *philo)
{
	if (get_forks(philo) != 0)
		return ;
	sem_wait(philo->saying);
	say_eating(philo);
	sem_post(philo->saying);
	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	sem_post(philo->each_eated_sem);
	ft_mssleep(*philo->time_to_eat, philo);
	sem_post(philo->forks->sem);
	sem_post(philo->forks->sem);
}

int			live(void *philo_arg)
{
	t_philo		*philo;
	uint8_t		*someone_dead_f;
	uint8_t		*each_eated_f;

	philo = (t_philo*)philo_arg;
	someone_dead_f = philo->someone_dead_f;
	each_eated_f = philo->each_eated_f;
	if (philo->id % 2)
		ft_mssleep(60, philo);
	while (1)
	{
		get_sleeping(philo);
		get_thinking(philo);
		get_eating(philo);
	}
	return (0);
}
