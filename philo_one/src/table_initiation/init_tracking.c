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

t_tracking	*init_tracking(t_table *table)
{
	t_tracking	*tracking;

	tracking = (t_tracking*)malloc(sizeof(t_tracking));
	if (tracking == NULL)
		return (NULL);
	tracking->args = table->args;
	tracking->philos = table->philos;
	tracking->each_eated_f_mutex = &table->each_eated_f_mutex;
	tracking->someone_dead_f = &table->someone_dead_f;
	tracking->each_eated_f = &table->each_eated_f;
	return (tracking);
}
