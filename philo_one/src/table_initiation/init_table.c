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

t_input_args	*parse_argumets(int argc, char **argv)
{
	t_input_args	*args;

	if (argc != 5 && argc != 6)
		return (NULL);
	if ((args = (t_input_args*)malloc(sizeof(t_input_args))) == NULL)
		return (NULL);
	args->nb_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->nb_of_must_eat = ft_atoi(argv[5]);
	else
		args->nb_of_must_eat = 0;
	return (args);
}

void		del_forks(t_fork **forks, uint32_t amount)
{
	uint32_t	i;

	i = 0;
	while (i < amount)
	{
		if ((*forks)[i].mutex_f != 0)
			pthread_mutex_destroy(&((*forks)[i].mutex));
		i += 1;
	}
	free(*forks);
	(*forks) = NULL;
}

t_fork		*init_forks(uint32_t amount)
{
	t_fork			*forks;
	uint32_t		i;

	forks = (t_fork*)malloc(sizeof(t_fork) * amount);
	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		forks[i].id = i;
		forks[i].mutex_f = 0;
		i += 1;
	}
	i = 0;
	while (i < amount)
	{
		if (pthread_mutex_init(&(forks[i].mutex), NULL) != 0)
		{
			del_forks(&forks, amount);
			return (NULL);
		}
		forks[i].mutex_f = 1;
		i += 1;
	}
	return (forks);
}

void		del_msgs(t_msgs **msgs)
{
	if ((*msgs)->eating != NULL)
	{
		free((*msgs)->eating);
		(*msgs)->eating = NULL;
	}
	if ((*msgs)->sleeping != NULL)
	{
		free((*msgs)->sleeping);
		(*msgs)->sleeping = NULL;
	}
	if ((*msgs)->thinking != NULL)
	{
		free((*msgs)->thinking);
		(*msgs)->thinking = NULL;
	}
	if ((*msgs)->dying != NULL)
	{
		free((*msgs)->dying);
		(*msgs)->dying = NULL;
	}
	free(*msgs);
	*msgs = NULL;
}

t_msgs		*init_msgs(void)
{
	t_msgs	*msgs;

	msgs = (t_msgs*)malloc(sizeof(t_msgs));
	if (msgs == NULL)
		return (NULL);
	msgs->eating = NULL;
	msgs->sleeping = NULL;
	msgs->thinking = NULL;
	msgs->dying = NULL;
	if ((msgs->eating = ft_strdup(EATING)) == NULL)
	{
		del_msgs(&msgs);
		return (NULL);
	}
	if ((msgs->sleeping = ft_strdup(SLEEPING)) == NULL)
	{
		del_msgs(&msgs);
		return (NULL);
	}
	if ((msgs->thinking = ft_strdup(THINKING)) == NULL)
	{
		del_msgs(&msgs);
		return (NULL);
	}
	if ((msgs->dying = ft_strdup(DIE)) == NULL)
	{
		del_msgs(&msgs);
		return (NULL);
	}
	return (msgs);
}

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
	philos = (t_philo*)malloc(sizeof(t_philo) * amount + 1);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		philos[i].id = i;
		philos[i].saying = &(table->saying);
		philos[i].someone_dead_f = &(table->someone_dead_f);
		philos[i].start_sim_time = &(table->start_sim_time);
		philos[i].time_to_die = &(table->args->time_to_die);
		philos[i].time_to_eat = &(table->args->time_to_eat);
		philos[i].time_to_sleep = &(table->args->time_to_sleep);
		philos[i].nb_of_must_eat = &(table->args->nb_of_must_eat);
		if ((philos[i].msgs = init_msgs()) == NULL)
		{
			free(philos);
			return (NULL);
		}
		i += 1;
	}
	return (philos);
}

void	del_table(t_table **table)
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
	if ((*table)->tracking != NULL)
		free((*table)->tracking);
	free(*table);
}

void	put_forks_to_philos(t_table *table)
{
	t_philo		*philos;
	t_fork		*forks;
	uint32_t	amount;
	uint32_t	i;

	philos = table->philos;
	forks = table->forks;
	amount = table->args->nb_of_philos;
	i = 0;
	while (i < amount)
	{
		philos[i].left_fork = &(forks[i]);
		if (i != amount - 1)
			philos[i].right_fork = &(forks[i + 1]);
		else
			philos[i].right_fork = &(forks[0]);
		i += 1;
	}
}

t_tracking	*init_tracking(t_table *table)
{
	t_tracking	*tracking;

	tracking = (t_tracking*)malloc(sizeof(t_tracking));
	if (tracking == NULL)
		return (NULL);
	tracking->args = table->args;
	tracking->philos = table->philos;
	tracking->someone_dead_f = &table->someone_dead_f;
	return (tracking);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	if ((table = (t_table*)malloc(sizeof(t_table))) == NULL)
		return (NULL);
	table->args = NULL;
	table->forks = NULL;
	table->philos = NULL;
	table->tracking = NULL;
	table->start_sim_time = 0;
	table->saying_mutex_f = 0;

	if (pthread_mutex_init(&(table->saying), NULL) != 0)
	{
		del_table(&table);
		return (NULL);
	}
	table->saying_mutex_f = 1;

	table->args = parse_argumets(argc, argv);
	if (table->args == NULL)
	{
		del_table(&table);
		return (NULL);
	}

	table->forks = init_forks(table->args->nb_of_philos);
	if (table->forks == NULL)
	{
		del_table(&table);
		return (NULL);
	}

	table->philos = init_philos(table);
	if (table->philos == NULL)
	{
		del_table(&table);
		return (NULL);
	}
	put_forks_to_philos(table);
	table->tracking = init_tracking(table);
	if (table->tracking == NULL)
	{
		del_table(&table);
		return (NULL);
	}
	return (table);
}
