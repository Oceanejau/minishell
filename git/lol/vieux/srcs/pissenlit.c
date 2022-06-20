/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pissenlit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:53:20 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/09 23:10:34 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	racine(t_soph *soph, t_hales *philos)
{
	int	x;

	x = -1;
	while (soph->nb_philo != 1 && ++x < soph->nb_philo)
		pthread_join(philos[x].thread_who, NULL);
	x = -1;
	while (++x < soph->nb_philo)
		pthread_mutex_destroy(&(soph->fork[x]));
	pthread_mutex_destroy(&(soph->scribe));
}

void	pissenlit(t_soph *soph, t_hales *p, int x)
{
	while (!(soph->all))
	{
		x = -1;
		while (++x < soph->nb_philo && !(soph->died))
		{
			pthread_mutex_lock(&(soph->meal_check));
			if (timer(p[x].t_eat, timestamp_in_ms()) > soph->t_die)
			{
				print_it(soph, x, "died");
				soph->died = 1;
			}
			pthread_mutex_unlock(&(soph->meal_check));
			usleep(100);
		}
		x = 0;
		if (soph->died)
			break ;
	while (soph->nb_eat != -1 && x < soph->nb_philo && p[x].eat
		>= soph->nb_eat - 1)
	{
		x++;
	}
		if (x == soph->nb_philo)
			soph->all = 1;
	}
}
