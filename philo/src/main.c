/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:00 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/18 16:24:33 by robertrinh    ########   odam.nl         */
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
	t_data data;
	
	memset(&data, 0, sizeof(t_data));
	if (ac != 5 && ac != 6)
		error_message();
	if (!input_check(av))
	{
		printf("Error, input not valid\n");
		return (EXIT_FAILURE);
	}
	//philos innit
	//params innit?
	
	return (EXIT_SUCCESS);
}
