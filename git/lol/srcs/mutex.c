/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:55:45 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:20:37 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	init_mutex(t_soph *soph)
{
	int	x;

	x = soph->nb_philo;
	while (--x >= 0)
	{
		if (pthread_mutex_init(&(soph->fork[x]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(soph->scribe), NULL))
		return (1);
	if (pthread_mutex_init(&(soph->meal_check), NULL))
		return (1);
	return (0);
}
