/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saying.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:28:01 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/06 16:28:03 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAYING_H
# define SAYING_H

# include <stdint.h>

# define STDOUT 1

void	print_preview(uint64_t time, int id);
void	say_msg(char *msg);

void	say_taking_fork(t_philo *philo);
void	say_eating(t_philo *philo);
void	say_thinking(t_philo *philo);
void	say_sleeping(t_philo *philo);
void	say_dying(t_philo *philo);

#endif
