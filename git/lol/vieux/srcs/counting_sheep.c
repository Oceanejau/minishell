/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_sheep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:06:50 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:16:43 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	counting_sheep(long long time, t_soph *soph)
{
	long long	t;

	t = timestamp_in_ms();
	while (!(soph->died))
	{
		if (timer(t, timestamp_in_ms()) >= time)
			break ;
		usleep(50);
	}
}
