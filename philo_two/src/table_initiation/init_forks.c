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
#include <stdio.h>

#include "utils.h"
#include "table_initiation.h"

void			del_forks(t_fork **forks)
{
	if ((*forks)->sem_f != 0)
	{
		sem_close((*forks)->sem);
		sem_unlink(FORKS_SEM);
	}
	(*forks)->sem_f = 0;
	free(*forks);
	(*forks) = NULL;
}

t_fork			*init_forks(uint32_t amount)
{
	t_fork			*forks;

	forks = (t_fork*)malloc(sizeof(t_fork));
	if (forks == NULL)
		return (NULL);
	forks->sem_f = 0;
	if((forks->sem = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 066, amount)) == SEM_FAILED)
	{
		write(2, OPEN_SEM_ERROR, ft_strlen(OPEN_SEM_ERROR));
		del_forks(&forks);
		return (NULL);
	}
	forks->sem_f = 1;
	return (forks);
}
