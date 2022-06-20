/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:55:01 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:22:55 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	starter(t_soph *soph, char **av)
{
	soph->nb_philo = ft_atoi(av[1]);
	soph->t_die = ft_atoi(av[2]);
	soph->t_eat = ft_atoi(av[3]);
	soph->t_sleep = ft_atoi(av[4]);
	soph->all = 0;
	soph->died = 0;
	if (soph->nb_philo < 1 || soph->t_die < 0 || soph->t_eat < 0
		|| soph->t_sleep < 0 || soph->nb_philo > 300)
		return (1);
	if (av[5])
	{
		soph->nb_eat = ft_atoi(av[5]);
		if (soph->nb_eat <= 0)
			return (1);
	}
	else
		soph->nb_eat = -1;
	if (init_mutex(soph))
		return (2);
	philo_thales(soph);
	return (0);
}
