/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_trackings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 18:01:42 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 18:01:42 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "table_initiation.h"

t_tracking	*init_trackings(t_table *table)
{
	t_tracking	*trackings;
	int			amount;
	int			i;

	amount = table->args->nb_of_philos;
	trackings = (t_tracking*)malloc(sizeof(t_tracking) * amount);
	if (trackings == NULL)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		trackings[i].args = table->args;
		trackings[i].philo = &table->philos[i];
		trackings[i].someone_dead_f = &table->someone_dead_f;
		trackings->each_eated_f = &table->each_eated_f;
		i += 1;
	}
	return (trackings);
}
