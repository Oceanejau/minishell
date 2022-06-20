/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   festin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:54:31 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/09 23:28:54 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	festin(t_hales *philo)
{
	t_soph	*soph;

	soph = philo->soph;
	if (philo->who == philo->soph->nb_philo)
	{
		write(1, "HELLO\n", 6);
		pthread_mutex_lock(&(soph->fork[philo->r_fork]));
		print_it(soph, philo->who, "has taken a fork");
	}
	pthread_mutex_lock(&(soph->fork[philo->l_fork]));
	print_it(soph, philo->who, "has taken a fork");
	if (philo->who != philo->soph->nb_philo)
	{
		pthread_mutex_lock(&(soph->fork[philo->r_fork]));
		print_it(soph, philo->who, "has taken a fork");
	}
	pthread_mutex_lock(&(soph->meal_check));
	print_it(soph, philo->who, "is eating");
	philo->t_eat = timestamp_in_ms();
	pthread_mutex_unlock(&(soph->meal_check));
	counting_sheep(soph->t_eat, soph);
	//	(philo->t_eat)++;
	(philo->eat)++;
	pthread_mutex_unlock(&(soph->fork[philo->r_fork]));
	pthread_mutex_unlock(&(soph->fork[philo->l_fork]));
}
