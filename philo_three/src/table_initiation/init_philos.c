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

void		init_params(t_philo *philo, t_table *table)
{
	philo->forks = table->forks;
	philo->saying = table->saying;
	philo->someone_dead_f = &(table->someone_dead_f);
	philo->each_eated_f = &(table->each_eated_f);
	philo->start_sim_time = &(table->start_sim_time);
	philo->time_to_die = &(table->args->time_to_die);
	philo->time_to_eat = &(table->args->time_to_eat);
	philo->time_to_sleep = &(table->args->time_to_sleep);
	philo->nb_of_must_eat = &(table->args->nb_of_must_eat);
	philo->last_eating_time = 0;
	philo->eating_counter = 0;
	philo->time_of_death = 0;
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
		philos[i].id = i + 1;
		if ((philos[i].msgs = init_msgs()) == NULL)
		{
			free(philos);
			return (NULL);
		}
		init_params(&philos[i], table);
		i += 1;
	}
	return (philos);
}
