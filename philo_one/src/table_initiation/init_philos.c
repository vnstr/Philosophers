/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:48:19 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 17:48:20 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "table_initiation.h"

void		del_philos(t_philo **philos, uint32_t amount)
{
	uint32_t	i;

	i = 0;
	while (i < amount)
	{
		if (((*philos)[i]).msgs != NULL)
			del_msgs(&(((*philos)[i]).msgs));
		i += 1;
	}
	free(*philos);
	*philos = NULL;
}

t_philo		*init_philos(t_table *table)
{
	t_philo		*philos;
	uint32_t	amount;
	uint32_t	i;

	amount = table->args->nb_of_philos;
	philos = (t_philo*)malloc(sizeof(t_philo) * amount);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		if ((philos[i].msgs = init_msgs()) == NULL)
		{
			free(philos);
			return (NULL);
		}
		philos[i].saying = &(table->saying);
		philos[i].someone_dead_f = &(table->someone_dead_f);
		philos[i].each_eated_f = &(table->each_eated_f);
		philos[i].start_sim_time = &(table->start_sim_time);
		philos[i].time_to_die = &(table->args->time_to_die);
		philos[i].time_to_eat = &(table->args->time_to_eat);
		philos[i].time_to_sleep = &(table->args->time_to_sleep);
		philos[i].nb_of_must_eat = &(table->args->nb_of_must_eat);
		philos[i].last_eating_time = 0;
		philos[i].eating_counter = 0;
		philos[i].time_of_death = 0;
		philos[i].id = i + 1;


		philos[i].turn = &(table->turn);

		i += 1;
	}
	return (philos);
}
