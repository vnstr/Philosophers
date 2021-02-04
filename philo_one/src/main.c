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

#include "table_initiation.h"

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
	for (uint32_t i = 0; i < table->args->nb_of_philos; i += 1)
	{
		printf("\nphilos_id[%u]:\nleft_fork_id =  |%u|\nleft_right_id = |%u|\n",
				table->philos[i].id,
				table->philos[i].left_fork->id,
				table->philos[i].right_fork->id);
	}

	printf("\n-------------------\n");
}

static void	exit_with_arguments_error(void)
{
	write(2, "Error: not valid argumets\n", 27);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_table		*table;

	if ((table = init_table(argc, argv)) == NULL)
		exit_with_arguments_error();
	print_table(table);
	del_table(&table);
	sleep(20);
	return (0);
}
