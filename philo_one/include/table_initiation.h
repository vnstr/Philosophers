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

# define CREATE_THREAD_ERROR "Error: can't create thread\n"
# define JOIN_THREAD_ERROR "Error: can't join thread\n"

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

# define STDOUT 1

# define EATING ": \"I eat\"\n"
# define SLEEPING ": \"I sleep\"\n"
# define THINKING ": \"I think\"\n"
# define DIE ": \"I am dying\"\n"

typedef struct		s_msgs
{
	char			*eating;
	char			*sleeping;
	char			*thinking;
	char			*dying;
}					t_msgs;

typedef struct		s_philo
{
	pthread_t		thread;
	t_msgs			*msgs;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*saying;
	uint8_t			*someone_dead_f;
	uint64_t		*start_sim_time;
	uint32_t		*time_to_die;
	uint32_t		*time_to_eat;
	uint32_t		*time_to_sleep;
	uint32_t		*nb_of_must_eat;
	uint64_t		last_eating_time;
	int				id;
}					t_philo;

typedef struct		s_tracking
{
	pthread_t		thread;
	t_input_args	*args;
	t_philo			*philos;
	uint8_t			*someone_dead_f;
}					t_tracking;

typedef struct		s_table
{
	t_input_args	*args;
	t_fork			*forks;
	t_philo			*philos;
	t_tracking		*tracking;
	pthread_mutex_t	saying;
	uint64_t		start_sim_time;
	uint8_t			saying_mutex_f;
	uint8_t			someone_dead_f;
}					t_table;

t_table				*init_table(int argc, char **argv);
void				del_table(t_table **table);

#endif
