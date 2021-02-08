/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 18:38:48 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/05 18:38:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "table_initiation.h"

int		start_simulation(t_table *table);
void	*live(void *philo_arg);
void	*track(void *tracking);

void	get_dying(t_philo *philo);

#endif
