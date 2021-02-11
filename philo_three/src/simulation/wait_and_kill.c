/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_and_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:15:51 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/11 17:15:53 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdint.h>

#include "table_initiation.h"

void	kill_philos(t_killer *killer)
{
	int	i;

	i = 0;
	while (i < killer->args->nb_of_philos)
	{
		kill(killer->philos[i].pid, 9);
		i += 1;
	}
	exit(0);
}

void	*check_each_eated(void *killer_arg)
{
	t_killer	*killer;
	uint64_t	amount;

	killer = (t_killer*)killer_arg;
	amount = killer->args->nb_of_philos * killer->args->nb_of_must_eat;
	while (amount)
	{
		sem_wait(killer->each_eated_sem);
		amount -= 1;
	}
	kill_philos(killer);
	return (NULL);
}

void	wait_and_kill(t_killer *killer)
{
	if (killer->args->nb_of_must_eat != 0)
		pthread_create(&killer->each_eated_checker, NULL, check_each_eated, (void*)killer);
	sem_wait(killer->someone_dead_sem);
	kill_philos(killer);
}
