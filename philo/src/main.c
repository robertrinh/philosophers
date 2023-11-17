/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:00 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/11/17 16:26:32 by qtrinh        ########   odam.nl         */
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
	//struct callen;
	int i = 0;
	if (ac != 5 && ac != 6)
		error_message();
	printf("%c\n", av[5][i]);
	//parse input
	//philos innit
	//params innit?
	
	
	return (EXIT_SUCCESS);
}
