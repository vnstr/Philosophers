/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saying.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:25:13 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/06 16:25:14 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "table_initiation.h"
#include "saying.h"
#include "libft.h"
#include "utils.h"

void	say_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

void	say_eating(t_philo *philo)
{
	uint64_t	start_sim_time;

	start_sim_time = *philo->start_sim_time;
	print_preview(get_sim_mstime(start_sim_time), philo->id);
	say_msg(philo->msgs->eating);
}

void	say_thinking(t_philo *philo)
{
	uint64_t	start_simulation;

	start_simulation = *philo->start_sim_time;
	print_preview(get_sim_mstime(start_simulation), philo->id);
	say_msg(philo->msgs->thinking);
}

void	say_sleeping(t_philo *philo)
{
	uint64_t	start_sim_time;

	start_sim_time = *philo->start_sim_time;
	print_preview(get_sim_mstime(start_sim_time), philo->id);
	say_msg(philo->msgs->sleeping);
}

void	say_dying(t_philo *philo)
{
	uint64_t	start_simulation;

	start_simulation = *philo->start_sim_time;
	print_preview(get_sim_mstime(start_simulation), philo->id);
	say_msg(philo->msgs->dying);
}

void	say_taking_fork(t_philo *philo)
{
	uint64_t	start_simulation;

	start_simulation = *philo->start_sim_time;
	print_preview(get_sim_mstime(start_simulation), philo->id);
	say_msg(philo->msgs->taking_fork);
}
