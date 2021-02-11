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
# include <semaphore.h>
# include <stdint.h>

# define INIT_TABLE_ERROR "Error: can't init table\n"
# define CREATE_THREAD_ERROR "Error: can't create thread\n"
# define JOIN_THREAD_ERROR "Error: can't join thread\n"
# define OPEN_SEM_ERROR "Error: can't open semaphore\n"
# define CREATE_FORK_ERROR "Error: can't create child process\n"

# define FORKS_SEM "forks_sem"
# define SAYNG_SEM "saying_sem"
# define EACH_EATED_F_SEM "each_eated_f_sem"
# define SOMEONE_DEAD_SEM "someone_dead_sem"
# define EACH_EATED_SEM "each_eated_sem"

typedef struct		s_input_args
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_must_eat;
}					t_input_args;

t_input_args		*parse_argumets(int argc, char **argv);

typedef struct		s_fork
{
	sem_t			*sem;
	uint8_t			sem_f;
}					t_fork;

void				del_forks(t_fork **forks);
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
	t_msgs			*msgs;
	t_fork			*forks;
	sem_t			*saying;
	sem_t			*each_eated_sem;
	uint8_t			*someone_dead_f;
	uint8_t			*each_eated_f;
	uint64_t		*start_sim_time;
	int				*time_to_die;
	int				*time_to_eat;
	int				*time_to_sleep;
	int				*nb_of_must_eat;
	uint64_t		last_eating_time;
	uint64_t		eating_counter;
	uint64_t		time_of_death;
	int				id;
	int				pid;
}					t_philo;

typedef struct		s_tracking
{
	pthread_t		thread;
	t_input_args	*args;
	t_philo			*philo;
	sem_t			*someone_dead_sem;
	uint8_t			*someone_dead_f;
	uint8_t			*each_eated_f;
}					t_tracking;

typedef struct		s_killer
{
	t_input_args	*args;
	t_philo			*philos;
	pthread_t		each_eated_checker;
	sem_t			*someone_dead_sem;
	sem_t			*each_eated_sem;
}					t_killer;

typedef struct		s_table
{
	t_input_args	*args;
	t_fork			*forks;
	t_philo			*philos;
	t_tracking		*trackings;
	t_killer		*killer;
	sem_t			*saying;
	sem_t			*someone_dead_sem;
	sem_t			*each_eated_sem;
	uint64_t		start_sim_time;
	uint8_t			saying_sem_f;
	uint8_t			someone_dead_sem_f;
	uint8_t			each_eated_sem_f;
	uint8_t			someone_dead_f;
	uint8_t			each_eated_f;
}					t_table;

void				del_philos(t_philo **philos, uint32_t amount);
t_philo				*init_philos(t_table *table);

t_tracking			*init_trackings(t_table *table);

t_killer			*init_killer(t_table *table);

t_table				*init_table(int argc, char **argv);
void				del_table(t_table **table);

#endif
