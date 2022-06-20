/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_thread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:54:04 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/09 23:04:59 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*p_thread(void *void_philosopher)
{
	int				x;
	t_hales			*philo;
	t_soph			*soph;

	x = 0;
	philo = (t_hales *)void_philosopher;
	soph = philo->soph;
	if (philo->who % 2)
		usleep(1000);
	while (!(soph->died))
	{
		festin(philo);
		if (soph->all)
			break ;
		print_it(soph, philo->who, "is sleeping");
		counting_sheep(soph->t_sleep, soph);
		print_it(soph, philo->who, "is thinking");
		x++;
	}
	return (NULL);
}
