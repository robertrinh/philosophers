/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/18 15:09:20 by robertrinh    #+#    #+#                 */
/*   Updated: 2024/01/03 18:58:53 by qtrinh        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	philo_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long int	philo_atol(const char *str)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (philo_isdigit(*str))
	{
			result = result * 10 + (*str - '0');
			str++;
	}
	return (sign * result);
}

bool	input_check(char **av)
{
	int	str;
	int	j;
	
	str = 1;
	while (av[str])
	{
		j = 0;
		if (av[str][j] == '\0')
			return (false);
		while (av[str][j])
		{
			if (!philo_isdigit(av[str][j]))
			{
				write(2, "input invalid bro\n", 19);
				return (false);
			}
			j++;
		}
		str++;
	}
	return (true);
}
