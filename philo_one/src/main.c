/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:22:09 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/03 18:22:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "table_initiation.h"
#include "simulation.h"

int			main(int argc, char **argv)
{
	t_table		*table;

	if ((table = init_table(argc, argv)) == NULL)
		return (1);
	if (start_simulation(table) != 0)
	{
		del_table(&table);
		write(2, "Error: simulation\n", 19);
		exit(1);
	}
	del_table(&table);
	return (0);
}
