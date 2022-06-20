/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:50:07 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:24:27 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	main(int ac, char **av)
{
	t_soph	soph;
	int		ret;

	if (ac < 5 || ac > 6)
		return (write_error("[number_of_times_each_philosopher_must_eat]", 1));
	ret = starter(&soph, av);
	if (ret)
		return (err(ret));
	if (philo(&soph))
		return (write_error("Thread creating failed", 0));
	return (0);
}
