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
		{
			pthread_mutex_destroy(&((*forks)[i].mutex));
		}
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

t_philo		*init_philos(uint32_t amount)
{
	t_philo		*philos;
	uint32_t	i;

	philos = (t_philo*)malloc(sizeof(t_philo) * amount + 1);
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		philos[i].id = i;
		i += 1;
	}
	return (philos);
}

void	del_table(t_table **table)
{
	if ((*table)->philos != NULL)
		free((*table)->philos);
	del_forks(&((*table)->forks), (*table)->args->nb_of_philos);
	if ((*table)->args != NULL)
		free((*table)->args);
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

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	if ((table = (t_table*)malloc(sizeof(t_table))) == NULL)
		return (NULL);
	table->args = NULL;
	table->philos = NULL;
	table->forks = NULL;
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
	table->philos = init_philos(table->args->nb_of_philos);
	if (table->philos == NULL)
	{
		del_table(&table);
		return (NULL);
	}
	put_forks_to_philos(table);
	return (table);
}
