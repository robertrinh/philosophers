/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:00 by qtrinh        #+#    #+#                 */
/*   Updated: 2024/01/03 18:59:08 by qtrinh        ########   odam.nl         */
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

int	main(int ac, char **av)
{
	t_data *data;

	data = NULL;
	if (ac != 5 && ac != 6)
		error_message();
	if (!init_bruv(data, ac, av))
		return (EXIT_FAILURE);
	//TODO thread, monitor, join?
	free(data); //moet ik alles free?
	return (EXIT_SUCCESS);
}
