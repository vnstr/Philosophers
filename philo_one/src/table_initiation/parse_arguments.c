/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:32:06 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 17:32:06 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "table_initiation.h"

t_input_args	*parse_argumets(int argc, char **argv)
{
	t_input_args	*args;

	if (argc != 5 && argc != 6)
		return (NULL);
	if ((args = (t_input_args*)malloc(sizeof(t_input_args))) == NULL)
		return (NULL);
	args->nb_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->nb_of_must_eat = ft_atoi(argv[5]);
	else
		args->nb_of_must_eat = 0;
	return (args);
}
