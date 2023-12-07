/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:12 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/12/07 17:42:46 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* memset */
#include <string.h>

/* printf */
# include <stdio.h>

/* pthread functions */
# include <pthread.h>

/* malloc, free */
# include <stdlib.h>
# include <stdbool.h>

/* write, usleep */
# include <unistd.h>

/* gettimeofday */
# include <sys/time.h>
//check if you need any of those in what files and put those headers there!

typedef struct t_philo	s_philo;

# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct	s_data
{
	int				philo_n;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				max_meal;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	struct s_philo			*philo;
}	t_data;

typedef struct	s_philo
{
	t_data	*data;
	int		id;
	int		meal_count;
	unsigned long	last_ate;
	bool	eating;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	meal_lock;
}	t_philo;

/* parsing */
bool	input_check(char **av);
bool	data_init(t_data *data, int ac, char **av);
bool	init_bruv(t_data *data, int ac, char **av);

long int	philo_atol(const char *str);
void	*philo_calloc(size_t count, size_t size);

void	clean_mutex(t_data *data);

#endif