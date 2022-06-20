/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:26 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/21 01:35:48 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	time_fork(long long ms, int who)//who = philosphe id
{
	int		x;
	char	*str;

	x = 0;
	str = ft_itoa(ms);
	while (str[x] != '\0')
		x++;
	write(1, str, x);
	write(1, " ", 1);
	x = 0;
	str = ft_itoa(who);
	while (str[x] != '\0')
		x++;
	write(1, str, x);
	write(1, " has taken a fork\n", 18);
	return ;
}

void	init_theophraste(t_philo *soph)
{
	int	x;

	x = 0;
	while (x < soph->nb_philo)
	{
		soph->phraste[x].sophilos = x;//philosophe id
		soph->phraste[x].fork = 1;
		soph->phraste[x].eat = 0;
		soph->phraste[x].sleep = 0;
		soph->phraste[x].think = 0;
		soph->phraste[x].died = 0;
		soph->phraste[x].nb_meal = 0;
		x++;
	}
	return ;
}

long long	time_start(void)//renvoie temps a deduire t-init t-maintenant
{
	struct timeval	time;
	long long int	t_time;

	gettimeofday(&time, NULL);
//	printf("time in fonc time = %ld\n", time.tv_sec / 1000);/////////////
//	t_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));//renvoie une valeure a deduire d lacienne pour obtenirle nb de temps ecoule
}

int	init_struct(int ac, char **av, t_philo *soph)
{
	if (ac < 5 || ac > 6)
		return (-1);
	soph->nb_philo = ft_atoi(av[1], soph);//nombre de philosopher
	soph->t_die = ft_atoi(av[2], soph);//time to die
	soph->t_eat = ft_atoi(av[3], soph);//time to eat
	soph->t_sleep = ft_atoi(av[4], soph);//time to sleep
	soph->six = 0;//peut etre init dans une autre fonction
	soph->fork = ac;
	if (soph->nb_philo < 1 || soph->t_die <= 0 || soph->t_eat <= 0
		|| soph->t_sleep <= 0)
		return (-2);
	if (ac == 6)
	{
		soph->six = 1;
		soph->nb_eat = ft_atoi(av[5], soph);//number of time each must eat
		if (soph->atoi == -1)
			return (-2);
		if (soph->nb_eat < 0)// si nb eat == 0 tout demarre personne ne mange et ca se finit?
			return (-3);
	}
	else
		soph->nb_eat = -1;
	init_theophraste(soph);
	soph->run = time_start();
	printf("time = %lld\n", soph->run);//////
	return (0);
}

void	write_error(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	write(2, "Error :\n ", 8);
	write(2, str, x);
	write(2, ".\n", 2);
	return ;
}

int	retinol_init(t_philo *soph)
{
//	printf("soph->ret = %d\n", soph->ret);
	if (soph->ret == -1)
		write_error("Wrong number of arguments");
	else if (soph->ret == -2)
		write_error("Arguments must be digits only, bigger than 0");
	else if (soph->ret == -3)
		write_error("Nb times each must eat has to be bigger or equal 0");
	return (-1);
}

void	activ_philo(t_philo *soph, int x)
{
	if (mutex)
	{
		while (temps)
		{
			
		}
	}
	while (temps pense)
		while (temps sleep)
	soph->s_heo[x].nb_meal++;
	return ;
}

void	get_to_work(t_philo *soph)
{
	int	x;

	x = 0;
	while (x < soph->nb_philo)
	{
		soph->phraste[x].fork = 1;
		soph-phraste[x].fork = 2;
		x++;
	}
	soph->phraste[x].fork = 0;
/*		tous les philos sont pas passe ici)
		lance tous les fonctions des philosophes vivants
		{
			case un mutex;
			prends une fourchette;lock mutex
				prendre lautrelock mutex;
			print mange;
			de lock la fourchette
				va dormir jusqua x temps
				puis va penser
				tant que le temps secoule jusauq lq mort

		}
	nb de fois ou ta mange+++;
*/
	return;
}

int	main(int ac, char **av)
{
	t_philo	soph;

	soph.atoi = 0;
	soph.ret = init_struct(ac, av, &soph);
	if (soph.ret < 0)
		return (retinol_init(&soph));
	get_to_work(&soph);	
	return (0);
}

/*
   on doit gerer les signes + dans les params?
 */
