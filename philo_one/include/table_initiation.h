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

# define INIT_TABLE_ERROR "Error: can't init table\n"
# define CREATE_THREAD_ERROR "Error: can't create thread\n"
# define JOIN_THREAD_ERROR "Error: can't join thread\n"
# define INIT_MUTEX_ERROR "Error: can't init mutex\n"

typedef struct		s_input_args
{
	uint32_t		nb_of_philos;
	uint32_t		time_to_die;
	uint32_t		time_to_eat;
	uint32_t		time_to_sleep;
	uint32_t		nb_of_must_eat;
}					t_input_args;

t_input_args		*parse_argumets(int argc, char **argv);

typedef struct		s_fork
{
	pthread_mutex_t	mutex;
	uint8_t			mutex_f;
	int				id;
}					t_fork;

void				del_forks(t_fork **forks, uint32_t amount);
t_fork				*init_forks(uint32_t amount);

# define STDOUT 1

# define TAKING_FORKS " has taken a fork\n"
# define EATING " is eating\n"
# define SLEEPING " is sleeping\n"
# define THINKING " is thinking\n"
# define DIE " died\n"

typedef struct		s_msgs
{
	char			*taking_fork;
	char			*eating;
	char			*sleeping;
	char			*thinking;
	char			*dying;
}					t_msgs;

void				del_msgs(t_msgs **msgs);
t_msgs				*init_msgs(void);

typedef struct		s_philo
{
	pthread_t		thread;
	t_msgs			*msgs;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*saying;
	uint8_t			*someone_dead_f;
	uint8_t			*each_eated_f;
	uint64_t		*start_sim_time;
	uint32_t		*time_to_die;
	uint32_t		*time_to_eat;
	uint32_t		*time_to_sleep;
	uint32_t		*nb_of_must_eat;
	uint64_t		last_eating_time;
	uint64_t		eating_counter;
	uint64_t		time_of_death;
	int				id;

	pthread_mutex_t	*turn;
}					t_philo;

typedef struct		s_tracking
{
	pthread_t		thread;
	t_input_args	*args;
	t_philo			*philos;
	pthread_mutex_t	*each_eated_f_mutex;
	uint8_t			*someone_dead_f;
	uint8_t			*each_eated_f;
}					t_tracking;

typedef struct		s_table
{
	t_input_args	*args;
	t_fork			*forks;
	t_philo			*philos;
	t_tracking		*tracking;
	pthread_mutex_t	turn;
	pthread_mutex_t	saying;
	pthread_mutex_t	each_eated_f_mutex;
	uint64_t		start_sim_time;
	uint8_t			saying_mutex_f;
	uint8_t			someone_dead_f;
	uint8_t			each_eated_f;
	uint8_t			each_eated_f_mutex_f;
}					t_table;

void				del_philos(t_philo **philos, uint32_t amount);
t_philo				*init_philos(t_table *table);

t_tracking			*init_tracking(t_table *table);

t_table				*init_table(int argc, char **argv);
void				del_table(t_table **table);

void				put_forks_to_philos(t_table *table);

#endif
