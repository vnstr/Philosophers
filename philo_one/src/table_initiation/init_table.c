/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:35:13 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/04 18:35:14 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "table_initiation.h"

void		del_table(t_table **table)
{
	if ((*table)->philos != NULL)
	{
		del_philos(&((*table)->philos), (*table)->args->nb_of_philos);
	}
	del_forks(&((*table)->forks), (*table)->args->nb_of_philos);
	if ((*table)->args != NULL)
		free((*table)->args);
	if ((*table)->saying_mutex_f != 0)
		pthread_mutex_destroy(&((*table)->saying));
	if ((*table)->each_eated_f_mutex_f != 0)
		pthread_mutex_destroy(&((*table)->each_eated_f_mutex));
	if ((*table)->tracking != NULL)
		free((*table)->tracking);
	free(*table);
}

static int	init_mutexs(t_table *table)
{
	if (pthread_mutex_init(&(table->saying), NULL) != 0)
		return (1);
	table->saying_mutex_f = 1;
	if (pthread_mutex_init(&(table->each_eated_f_mutex), NULL) != 0)
		return (1);
	table->each_eated_f_mutex_f = 1;
	return (0);
}

static int	init_env(t_table *table, int argc, char **argv)
{
	if (init_mutexs(table) != 0)
		return (1);
	if ((table->args = parse_argumets(argc, argv)) == NULL)
		return (1);
	if ((table->forks = init_forks(table->args->nb_of_philos)) == NULL)
		return (1);
	if ((table->philos = init_philos(table)) == NULL)
		return (1);
	if ((table->tracking = init_tracking(table)) == NULL)
		return (1);
	put_forks_to_philos(table);
	return (0);
}

t_table		*init_table(int argc, char **argv)
{
	t_table	*table;

	if ((table = (t_table*)malloc(sizeof(t_table))) == NULL)
		return (NULL);
	table->args = NULL;
	table->forks = NULL;
	table->philos = NULL;
	table->tracking = NULL;

	pthread_mutex_init(&(table->turn), NULL);

	table->start_sim_time = 0;
	table->saying_mutex_f = 0;
	table->someone_dead_f = 0;
	table->each_eated_f = 0;
	if (init_env(table, argc, argv) != 0)
	{
		del_table(&table);
		write(2, INIT_TABLE_ERROR, ft_strlen(INIT_TABLE_ERROR));
		return (NULL);
	}
	return (table);
}
