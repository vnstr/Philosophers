/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_initiation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:36:47 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/04 18:36:47 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_INITIATION_H
# define TABLE_INITIATION_H

# include <pthread.h>
# include <stdint.h>

typedef struct		s_input_args
{
	uint32_t		nb_of_philos;
	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	uint32_t		nb_of_must_eat;
}					t_input_args;

typedef struct		s_fork
{
	pthread_mutex_t	mutex;
	uint8_t			mutex_f;
	int				id;
}					t_fork;

# define EATING "I eat\n"
# define SLEEPING "I sleep\n"
# define THINKING "I think\n"
# define DIE "I am dying\n"

typedef struct		s_msgs
{
	char			*eating;
	char			*sleeping;
	char			*thinking;
	char			*die;
}					t_msgs;

typedef struct		s_philo
{
	pthread_t		philo;
	int				id;
	t_msgs			*msgs;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*saying;
}					t_philo;

typedef struct		s_table
{
	t_input_args	*args;
	t_fork			*forks;
	t_philo			*philos;
	pthread_mutex_t	saying;
}					t_table;

t_table				*init_table(int argc, char **argv);
void				del_table(t_table **table);

#endif
