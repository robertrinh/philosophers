/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:52:20 by qtrinh        #+#    #+#                 */
/*   Updated: 2024/01/03 18:59:02 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}

void	free_forks(t_data *data, int i)
{
	while (i < data->philo_n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i--;
	}
	free(data->forks);
}

void	free_structs(t_data *data)
{
	//destroy mutexes
	free(data->philo);
	free(data->forks);
	free(data);
}