/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/18 15:56:26 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/12/07 17:43:12 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void assign_fork(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_n)
	{
		data->philo[i].fork_left = &data->forks[i];
		if (i + 1 != data->philo_n)
			data->philo[i].fork_right = &data->forks[i];
	}
	data->philo[0].fork_right = &data->forks[i - 1];
}

static bool	forks_n_mutex_init(t_data *data)
{
	int	i;
	
	i = 0;
	data->forks = philo_calloc(sizeof(pthread_mutex_t), data->philo_n);
	if (!data->forks)
		return (printf("Forks init fail\n", false));
	while (i < data->philo_n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (i > 0)
			{
				pthread_mutex_destroy(&data->forks[i]);
				i--;
			}
			return (printf("Forks mutex init fail", NULL), false);
		}
		i++;
	}
	assign_fork(data);
	return (true);
}

bool	data_init(t_data *data, int ac, char **av)
{
	data->philo_n = philo_atol(av[1]);
	data->time_to_die = philo_atol(av[2]);
	data->time_to_eat = philo_atol(av[3]);
	data->time_to_sleep = philo_atol(av[4]);
	if (ac == 6)
	{
		data->max_meal = philo_atol(av[5]);
		if (data->max_meal <= 0)
			return (false);
	}
	else
		data->max_meal = -1;
	return (true);
}

static bool	philo_init(t_data *data)
{
	int	i;
	
	i = 0;
	data->philo = philo_calloc(data->philo_n, sizeof(t_philo));
	if (!data->philo)
		return (printf("philo init fail"), false);
	while (i < data->philo_n)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_ate = 0;
		data->philo[i].eating = false;
		data->philo[i].data = data;
		i++;
	}
	if (!forks_n_mutex_init(data))
		return (printf("mutex init fail"), false);
	return (true);
}

bool	init_bruv(t_data *data, int ac, char **av)
{
	if (!input_check(av))
		return (false);
	if (!data_init(data, ac, av))
		return (false);
	if (!philo_init(data))
		return (clean_mutex(data), false); //clean mutexes
	return (true);
}
