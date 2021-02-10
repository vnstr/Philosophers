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
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

#include "table_initiation.h"
#include "simulation.h"
#include "utils.h"

void	print_table(t_table *table)
{
	printf("------ TABLE ------\n");

	printf("\n~~~~~~input args:\n\n");

	t_input_args	*args = table->args;
	printf("nb_of_philos = |%u|\n", args->nb_of_philos);
	printf("time_to_die = |%u|\n", args->time_to_die);
	printf("time_to_eat = |%u|\n", args->time_to_eat);
	printf("time_to_sleep = |%u|\n", args->time_to_sleep);
	printf("nb_of_must_eat = |%u|\n", args->nb_of_must_eat);

	printf("\n~~~~~~~~~~~~~~~~~\n");

	printf("\n~~~~~~~~messages:\n\n");

	printf("eating:   %s", table->philos->msgs->eating);
	printf("sleep:    %s", table->philos->msgs->sleeping);
	printf("thinking: %s", table->philos->msgs->thinking);
	printf("die:      %s", table->philos->msgs->dying);

	printf("\n~~~~~~~~~~~~~~~~~\n");

	//printf("\n~~~~~~~~~~~forks:\n\n");

	//printf("\n~~~~~~~~~~philos:\n");

	for (int32_t i = 0; i < table->args->nb_of_philos; i += 1)
	{
		printf("\nphilos_id[%u]\n", table->philos[i].id);
	}

	printf("\n~~~~~~~~~~~~~~~~~\n");

	/*
	printf("\n~~~~~~~trackings:\n\n");

		printf("trackings[0]philos[0].id = |%u|\n",
				table->trackings[0].philos[0].id);

	printf("\n~~~~~~~~~~~~~~~~~\n");
	*/

	printf("\n-------------------\n");
}

# include <sys/time.h>

int			main(int argc, char **argv)
{
	t_table		*table;

	if ((table = init_table(argc, argv)) == NULL)
		return (1);
	print_table(table);
	if (start_simulation(table) != 0)
	{
		del_table(&table);
		write(2, "Error: simulation\n", 19);
		exit(1);
	}
	del_table(&table);
	return (0);
}
