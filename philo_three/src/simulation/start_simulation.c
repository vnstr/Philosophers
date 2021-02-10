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
	t_tracking	*tracking;
	pid_t		id;
	int			amount;
	int			i;

	philos = table->philos;
	amount = table->args->nb_of_philos;
	i = 0;
	table->start_sim_time = get_mstime();
	while (i < amount)
	{
		tracking = &table->trackings[i];
		id = fork();
		if (id == 0)
		{
			pthread_create(&tracking->thread, NULL, track, (void*)tracking);
			live((void*)&philos[i]);
			exit(0);
		}
		i += 1;
	}
	return (i);
}

int			start_simulation(t_table *table)
{
	int			nb_of_philo_threads;
	int			killer_id;

	nb_of_philo_threads = table->args->nb_of_philos;
	if (create_forks(table) != nb_of_philo_threads)
		return (1);
	killer_id = fork();
	if (killer_id == 0)
	{
		sleep(10);
		exit(0);
	}
	waitpid(killer_id, NULL, 0);
	/*
	if (join_threads(table) != nb_of_philo_threads + 1)
		return (1);
	*/
	return (0);
}
