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

int			create_forks(t_table *table)
{
	t_philo		*philos;
	t_tracking	*trackings;
	pid_t		id;
	int			amount;
	int			i;

	philos = table->philos;
	trackings = table->trackings;
	amount = table->args->nb_of_philos;
	i = 0;
	table->start_sim_time = get_mstime();
	while (i < amount)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
		{
			pthread_create(&trackings[i].thread, NULL, track, (void*)&trackings[i]);
			live((void*)&philos[i]);
			pthread_join(trackings[i].thread, NULL);
			exit(0);
		}
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

	killer_pid = fork();
	if (killer_pid == 0)
	{
		wait_and_kill(table->killer);
		exit(0);
	}
	waitpid(killer_pid, NULL, 0);

	/*
	if (join_threads(table) != nb_of_philo_threads + 1)
		return (1);
	*/
	return (0);
}
