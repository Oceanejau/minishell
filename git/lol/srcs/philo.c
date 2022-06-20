/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:50:48 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/09 22:28:32 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	philo(t_soph *soph)
{
	int				x;
	t_hales			*phi;

	x = 0;
	phi = soph->thales;
	soph->first_t = timestamp_in_ms();
	while (x < soph->nb_philo)
	{
		if (pthread_create(&(phi[x].thread_who), NULL, p_thread, &(phi[x])))
			return (1);
		phi[x].t_eat = timestamp_in_ms();
		x++;
	}
	pissenlit(soph, soph->thales, -1);
	racine(soph, phi);
	return (0);
}

int	philo_thales(t_soph *soph)
{
	int	x;

	x = soph->nb_philo;
	while (--x >= 0)
	{
		soph->thales[x].who = x;
		soph->thales[x].eat = 0;
		soph->thales[x].l_fork = x;
		soph->thales[x].r_fork = (x + 1) % soph->nb_philo;
		soph->thales[x].t_eat = 0;
		soph->thales[x].soph = soph;
	}
	return (0);
}
