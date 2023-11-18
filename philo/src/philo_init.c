/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/18 15:56:26 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/11/18 16:13:20 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_init(t_data *data, int ac, char **av)
{
	data->philo_n = philo_atoi(av[1]);
	data->time_to_die = philo_atoi(av[2]);
	data->time_to_eat = philo_atoi(av[3]);
	data->time_to_sleep = philo_atoi(av[4]);
	if (ac == 6)
	{
		data->max_meal = philo_atoi(av[5]);
		if (data->max_meal <= 0)
			return (false);
	}
	else
		data->max_meal = -1;
	return (true);
}