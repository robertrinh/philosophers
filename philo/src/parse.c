/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: robertrinh <robertrinh@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/18 15:09:20 by robertrinh    #+#    #+#                 */
/*   Updated: 2023/12/07 17:44:30 by robertrinh    ########   odam.nl         */
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
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (philo_isdigit(*str))
	{
		{
			result = result * 10 + (*str - '0');
			str++;
		}
	}
	return (sign * result);
}

bool	input_check(char **av)
{
	int	str;
	int	j;
	
	str = 1;
	if ((philo_atol(av[str]) > 2700)) //max threads?
		return (false);
	while (av[str])
	{
		j = 0;
		if (av[str][j] == '\0')
			return (false);
		while (av[str][j])
		{
			if (!philo_isdigit(av[str][j]))
				return (false);
			j++;
		}
		str++;
	}
	return (true);
}