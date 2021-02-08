/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:35:53 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 17:35:54 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "table_initiation.h"

void			del_forks(t_fork **forks, uint32_t amount)
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

static void		init_id_and_mutex_f(t_fork *forks, uint32_t amount)
{
	uint32_t	i;

	i = 0;
	while (i < amount)
	{
		forks[i].id = i;
		forks[i].mutex_f = 0;
		i += 1;
	}
}

static uint32_t	init_mutexs(t_fork *forks, uint32_t amount)
{
	uint32_t	i;

	i = 0;
	while (i < amount)
	{
		if (pthread_mutex_init(&(forks[i].mutex), NULL) != 0)
			return (i);
		forks[i].mutex_f = 1;
		i += 1;
	}
	return (i);
}

t_fork			*init_forks(uint32_t amount)
{
	t_fork			*forks;

	forks = (t_fork*)malloc(sizeof(t_fork) * amount);
	if (forks == NULL)
		return (NULL);
	init_id_and_mutex_f(forks, amount);
	if (init_mutexs(forks, amount) != amount)
	{
		write(2, INIT_MUTEX_ERROR, ft_strlen(INIT_MUTEX_ERROR));
		del_forks(&forks, amount);
		return (NULL);
	}
	return (forks);
}
