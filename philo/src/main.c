/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qtrinh <qtrinh@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 16:45:00 by qtrinh        #+#    #+#                 */
/*   Updated: 2023/12/07 18:00:20 by robertrinh    ########   odam.nl         */
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
	
	if (ac != 5 && ac != 6)
		error_message();
	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("struct malloc error"), EXIT_FAILURE);
	memset(data, 0, sizeof(t_data));
	if (!init_bruv(data, ac, av))
		return(free(data), 1);
	// if (!input_check(av))
	// {
	// 	printf("Error, input not valid\n");
	// 	return (EXIT_FAILURE);
	// }
	//philos innit
	//params innit?
	//monitoring
	free(data);
	return (EXIT_SUCCESS);
}
