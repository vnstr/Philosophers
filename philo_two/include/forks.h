/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:40:39 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 14:43:50 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

# include "table_initiation.h"

void	put_right_fork(t_philo *philo);
void	put_left_fork(t_philo *philo);
void	get_right_fork(t_philo *philo);
void	get_left_fork(t_philo *philo);
void	get_forks(t_philo *philo);
void	put_forks(t_philo *philo);

#endif
