/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 17:38:13 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/12/07 17:46:08 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_mutex(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->philo_n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL; //nodig?
}