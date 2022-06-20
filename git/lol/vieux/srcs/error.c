/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:56:16 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:18:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	write_error(char *str, int x)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error:\n", 7);
	if (x == 1)
	{
		write(2, "./philo number_of_philos time_to_die", 36);
		write(2, " time_to_eat time_to_sleep ", 27);
	}
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	err(int error)
{
	if (error == 1)
		return (write_error("One or more arguments might be false", 0));
	if (error == 2)
		return (write_error("Mutex failed", 0));
	return (1);
}
