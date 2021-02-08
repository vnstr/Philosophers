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
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		return ;
	}

	sem_wait(philo->saying);
	say_dying(philo);
	*philo->someone_dead_f = 1;
	sem_post(philo->saying);

}

static void	get_sleeping(t_philo *philo)
{
	sem_wait(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		sem_post(philo->saying);
		return ;
	}
	say_sleeping(philo);
	sem_post(philo->saying);
	ft_mssleep(*philo->time_to_sleep);
}

static void	get_thinking(t_philo *philo)
{
	sem_wait(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		sem_post(philo->saying);
		return ;
	}
	say_thinking(philo);
	sem_post(philo->saying);
}

static void	get_eating(t_philo *philo)
{
	sem_wait(philo->forks->sem);

	sem_wait(philo->saying);
	say_taking_fork(philo);
	sem_post(philo->saying);

	sem_wait(philo->forks->sem);

	sem_wait(philo->saying);
	say_taking_fork(philo);
	sem_post(philo->saying);

	sem_wait(philo->saying);
	if (*philo->someone_dead_f != 0 || *philo->each_eated_f != 0)
	{
		sem_post(philo->saying);
		sem_post(philo->forks->sem);
		sem_post(philo->forks->sem);
		return ;
	}
	say_eating(philo);
	sem_post(philo->saying);
	philo->last_eating_time = get_sim_mstime(*philo->start_sim_time);
	philo->eating_counter += 1;
	ft_mssleep(*philo->time_to_eat);
	sem_post(philo->forks->sem);
	sem_post(philo->forks->sem);
}

void		*live(void *philo_arg)
{
	t_philo		*philo;
	uint8_t		*someone_dead_f;
	uint8_t		*each_eated_f;

	philo = (t_philo*)philo_arg;
	someone_dead_f = philo->someone_dead_f;
	each_eated_f = philo->each_eated_f;
	//if (philo->id % 2)
		//ft_mssleep(60);
	while (*someone_dead_f == 0 && *each_eated_f == 0)
	{
		get_sleeping(philo);
		get_thinking(philo);
		get_eating(philo);
	}
	ft_mssleep(philo->id);
	return (NULL);
}
