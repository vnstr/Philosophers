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

/*
**	args:
**		number_of_philos
**		time_to_die (lifetime after eating)
**		time_to_eat (philo will spend for eating)
**		time_to_sleep (philo will spend for sleep)
**		[number_of_times_each_philo_must_eat]
**
**		P.s. Time in miliseconds.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

typedef struct		s_input_args
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_times_each_philo_must_eat;
}					t_input_args;

t_input_args	*parse_argumets(int argc, char **argv)
{
	t_input_args	*args;

	if (argc < 5 || argc > 6)
		return (NULL);
	if ((args = (t_input_args*)malloc(sizeof(t_input_args))) == NULL)
		return (NULL);
	args->nb_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		args->nb_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	return (args);
}

void	exit_with_arguments_error(void)
{
	write(2, "Error: not valid argumets\n", 27);
	exit(1);
}

void	printf_input_args(t_input_args *args)
{
	printf("~~ input_args: ~~\n");
	printf("nb_of_philos = |%d|\n", args->nb_of_philos);
	printf("time_to_die = |%d|\n", args->time_to_die);
	printf("time_to_eat = |%d|\n", args->time_to_eat);
	printf("time_to_sleep = |%d|\n", args->time_to_sleep);
	printf("nb_of_times_each_philo_must_eat = |%d|\n", args->nb_of_times_each_philo_must_eat);
	printf("~~~~~~~~~~~~~~~~~\n");
}

int		main(int argc, char **argv)
{
	t_input_args	*args;

	if ((args = parse_argumets(argc, argv)) == NULL)
		exit_with_arguments_error();
	printf_input_args(args);
	free(args);
	return (0);
}
