/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:52:40 by ojauregu          #+#    #+#             */
/*   Updated: 2022/03/18 15:22:05 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	print_it(t_soph *soph, int x, char *str)
{
	pthread_mutex_lock(&(soph->scribe));
	if (!(soph->died))
	{
		printf("%lli ", timestamp_in_ms() - soph->first_t);
		printf("%i ", x + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(soph->scribe));
	return ;
}
