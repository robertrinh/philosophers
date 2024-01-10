/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:00 by qtrinh        #+#    #+#                 */
/*   Updated: 2024/01/10 16:24:12 by robertrinh    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error_message(void)
{
	write(2, "error, please use these args:\n", 31);
	write(2, "./philo\n", 9);
	write(2, "number of philos\n", 18);
	write(2, "time to die\n", 13);
	write(2, "time to eat\n", 13);
	write(2, "time to sleep\n", 15);
	write(2, "number of times eating (optional)\n", 35);
	return(EXIT_FAILURE);
}

void	monitor(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->philo_n)
		{
			//check death + eat count
			// return
			
			i++;
		}
		usleep(1000);
	}
}

static bool	threads_join(t_data *data, int last_thread)
{
	int	i;

	i = 0;
	while (i < last_thread)
	{
		if (pthread_join(data->philo[i].id, NULL) != 0)
		{
			write(2, "error joining threads\n", 23);
			return (false);
		}
		i++;
	}
	return (true);
}

void	*routine(void *philo)
{
	t_philo	*p_struct;

	p_struct = (t_philo *)philo;
	if (p_struct->id % 2) //if p_id is odd
		usleep(1000); //wait for a period of time
	//while (check stop) -> eat, sleep, think

	return (NULL);
}

static bool	create_threads(t_data *data, int threads)
{
	while (threads < data->philo_n)
	{
		if (pthread_create(&data->philo[threads].id, NULL, &routine, &data->philo[threads]) != 0)
		{
			threads_join(data, threads);
			//free(data)
			write(2, "error creating threads\n", 24);
			return (false);
		}
		threads++;
	}
	return (true);
}

int	run_simu(t_data *data)
{
	int	threads;

	threads = 0;
	//get starttime?
	//check last eaten time
	//create threads
	//join threads
	free(data); //moet alles freed worden?
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data *data;

	data = NULL;
	if (ac != 5 && ac != 6)
		return (error_message());
	if (!init_bruv(data, ac, av))
		return (EXIT_FAILURE);
	//TODO thread, monitor, join?
	return (run_simu(data));
}
