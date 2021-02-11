/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_killer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:18:09 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/11 17:18:11 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "table_initiation.h"

t_killer	*init_killer(t_table *table)
{
	t_killer	*killer;

	killer = (t_killer*)malloc(sizeof(t_killer));
	if (killer == NULL)
		return (NULL);
	killer->args = table->args;
	killer->philos = table->philos;
	killer->someone_dead_sem = table->someone_dead_sem;
	killer->each_eated_sem = table->each_eated_sem;
	return (killer);
}
