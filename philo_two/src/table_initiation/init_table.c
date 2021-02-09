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

#include "utils.h"
#include "table_initiation.h"

void		del_table(t_table **table)
{
	if ((*table)->philos != NULL)
		del_philos(&((*table)->philos), (*table)->args->nb_of_philos);
	if ((*table)->forks != NULL)
		del_forks(&((*table)->forks));
	if ((*table)->args != NULL)
		free((*table)->args);
	if ((*table)->saying_sem_f != 0)
	{
		sem_close((*table)->saying);
		sem_unlink(SAYNG_SEM);
	}
	if ((*table)->tracking != NULL)
		free((*table)->tracking);
	free(*table);
}

static int	init_sems(t_table *table)
{
	sem_unlink(SAYNG_SEM);
	if ((table->saying = sem_open(SAYNG_SEM, O_CREAT | O_EXCL, 066, 1))
			== SEM_FAILED)
	{
		write(2, OPEN_SEM_ERROR, ft_strlen(OPEN_SEM_ERROR));
		return (1);
	}
	table->saying_sem_f = 1;
	return (0);
}

static int	init_env(t_table *table, int argc, char **argv)
{
	if (init_sems(table) != 0)
		return (1);
	if ((table->args = parse_argumets(argc, argv)) == NULL)
		return (1);
	if ((table->forks = init_forks(table->args->nb_of_philos)) == NULL)
		return (1);
	if ((table->philos = init_philos(table)) == NULL)
		return (1);
	if ((table->tracking = init_tracking(table)) == NULL)
		return (1);
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
	table->start_sim_time = 0;
	table->saying_sem_f = 0;
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
