/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_bruv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/18 15:56:26 by robertrinh    #+#    #+#                 */
/*   Updated: 2024/01/03 18:58:22 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	forks_init(t_data *data)
{
	int	i;

	i = 0;
	data->forks = philo_calloc(data->philo_n, sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		write(2, "error malloc forks\n", 20);
		return (false);
	}
	while (i < data->philo_n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free_forks(data, i - 1);
			write(2, "mutex init fail, mutex destroy\n", 32);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	philo_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = philo_calloc(data->philo_n, sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "malloc error philo struct\n", 27);
		free_structs(data);
		return (false);
	}
	while (i < data->philo_n)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meal_count = 0;
		data->philo[i].eating = false;
		data->philo[i].fork_right = &data->forks[i];
		data->philo[i].fork_left = &data->forks[(i + 1) % data->philo_n];
		//philo[i].last_ate = get time
		i++;
	}
	return (true);
}

bool	data_init(t_data *data, int ac, char **av)
{
	data = philo_calloc(sizeof(t_data), 1);
	if (!data)
	{
		write(2, "data calloc fail", 17);
		return (false);
	}
	data->philo_n = philo_atol(av[1]);
	if (!forks_init(data))
		return (free(data), false);
	//TODO data mutex check?
	data->time_to_die = philo_atol(av[2]);
	data->time_to_eat = philo_atol(av[3]);
	data->time_to_sleep = philo_atol(av[4]);
	if (ac == 6)
		data->max_meal = philo_atol(av[5]);
	else
		data->max_meal = -1; //is this needed?
	return (true);
}

bool	init_bruv(t_data *data, int ac, char **av)
{
	if (!input_check(av))
		return (false);
	if (!data_init(data, ac, av))
		return (false);
	if (!philo_init(data))
		return (false);
	return (true);
}
