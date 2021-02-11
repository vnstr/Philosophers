/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:54:40 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/05 13:54:41 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "utils.h"
#include "simulation.h"
#include "table_initiation.h"
#include "utils.h"

static void	prepare_for_live(t_philo *philo, t_tracking *tracking)
{
	pthread_create(&tracking->thread, NULL, track,
										(void*)tracking);
	live((void*)philo);
	pthread_join(tracking->thread, NULL);
	exit(0);
}

static int	create_forks(t_table *table)
{
	t_philo		*philos;
	t_tracking	*trackings;
	int			amount;
	int			i;

	philos = table->philos;
	trackings = table->trackings;
	amount = table->args->nb_of_philos;
	i = 0;
	table->start_sim_time = get_mstime();
	while (i < amount)
	{
		if ((philos[i].pid = fork()) < 0)
		{
			write(2, CREATE_FORK_ERROR, ft_strlen(CREATE_FORK_ERROR));
			kill_philos(table->killer);
			return (i);
		}
		if (philos[i].pid == 0)
			prepare_for_live(&philos[i], &trackings[i]);
		i += 1;
	}
	return (i);
}

int			start_simulation(t_table *table)
{
	int			nb_of_philo_threads;
	int			killer_pid;

	nb_of_philo_threads = table->args->nb_of_philos;
	if (create_forks(table) != nb_of_philo_threads)
		return (1);
	if ((killer_pid = fork()) < 0)
	{
		write(2, CREATE_FORK_ERROR, ft_strlen(CREATE_FORK_ERROR));
		kill_philos(table->killer);
		return (1);
	}
	if (killer_pid == 0)
		wait_and_kill(table->killer);
	waitpid(killer_pid, NULL, 0);
	return (0);
}
