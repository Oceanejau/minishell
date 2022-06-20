/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:49:39 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/19 16:08:22 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

int	ft_atoi(const char *str, t_philo *soph)
{
	unsigned int	nb;
	int				x;

	x = 0;
	nb = 0;
	while (str[x] > 48 && str[x] < 57)
	{
		nb = nb * 10 + (str[x] - 48);
		x++;
	}
	if (str[x] != '\0' && (str[x] < 48 || str[x] > 57))
	{
		soph->atoi = -1;
		return (-1);
	}
	return (nb);
}
