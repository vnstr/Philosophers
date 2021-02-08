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

#include "utils.h"
#include "simulation.h"
#include "table_initiation.h"
#include "utils.h"

static int	creat_philo_threads(t_table *table)
{
	t_philo		*philos;
	int			amount;
	int			i;

	philos = table->philos;
	amount = table->args->nb_of_philos;
	i = 0;
	while (i < amount)
	{
		if (pthread_create(&philos[i].thread, NULL, live, (void*)&philos[i]))
		{
			ft_putstr_fd(CREATE_THREAD_ERROR, 2);
			return (i);
		}
		i += 1;
	}
	return (i);
}

static int	create_threads(t_table *table)
{
	t_tracking	*tracking;
	int			nb_of_philos;
	int			created_amount;

	tracking = table->tracking;
	nb_of_philos = table->args->nb_of_philos;
	table->start_sim_time = get_mstime();
	if ((created_amount = creat_philo_threads(table)) != nb_of_philos)
		return (created_amount);
	if (pthread_create(&tracking->thread, NULL, track, (void*)tracking))
	{
		ft_putstr_fd(CREATE_THREAD_ERROR, 2);
		return (created_amount);
	}
	return (created_amount + 1);
}

static int	join_philo_threads(t_table *table)
{
	t_philo		*philos;
	int			amount;
	int			i;

	philos = table->philos;
	amount = table->args->nb_of_philos;
	i = 0;
	while (i < amount)
	{
		if (pthread_join(philos[i].thread, NULL))
		{
			ft_putstr_fd(JOIN_THREAD_ERROR, 2);
			return (i);
		}
		i += 1;
	}
	return (i);
}

static int	join_threads(t_table *table)
{
	t_tracking	*tracking;
	uint32_t	nb_of_philos;
	uint32_t	joined_amount;

	tracking = table->tracking;
	nb_of_philos = table->args->nb_of_philos;
	if ((joined_amount = join_philo_threads(table)) != nb_of_philos)
		return (joined_amount);
	if (pthread_join(tracking->thread, NULL))
	{
		ft_putstr_fd(JOIN_THREAD_ERROR, 2);
		return (joined_amount);
	}
	return (joined_amount + 1);
}

int			start_simulation(t_table *table)
{
	int			nb_of_philo_threads;

	nb_of_philo_threads = table->args->nb_of_philos;
	if (create_threads(table) != nb_of_philo_threads + 1)
		return (1);
	if (join_threads(table) != nb_of_philo_threads + 1)
		return (1);
	return (0);
}
