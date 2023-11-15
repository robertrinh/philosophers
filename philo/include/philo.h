/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:12 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/15 17:28:18 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* memset */
# include <string.h>

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

# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

typedef struct s_data
{
	
}	t_data;

int	philo_atoi(const char *str);

#endif