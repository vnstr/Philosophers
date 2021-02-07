/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks_to_philos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:06:05 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 18:06:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_initiation.h"

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
