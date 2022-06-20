/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:19:52 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/19 16:34:35 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

typedef struct s_heo
{
	int			sophilos;//signature du philo
	int			fork;//0 1 ou 2
	int			eat;// besoin de 2 fork
	int			sleep;
	int			think;
	int			died;//1 == dead
	int			nb_meal;// 0 not yet
	pthread_t	sophie;
}				t_heo;

typedef struct s_philo
{
	int			nb_philo;//nb of philos
	int			t_die;//time to die
	int			t_eat;//time to eat
	int			t_sleep;//time to sleep
	int			six;//if six args if 1 nb-eat dclrd if 0 nbeat not dclrd
	int			nb_eat;//nb time each must eat
	int			fork;
	int			ret;//error return
	long long int			run;//time start
	int			atoi;
	t_heo		phraste[200];
}				t_philo;

int			ft_atoi(const char *str, t_philo *soph);
char 		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
int			retinol_start(t_philo *soph, int ac);
void		write_error(char *str);
void		init_theophraste(t_philo *soph);
long long	time_start(void);
int			init_struct(int ac, char **av, t_philo *soph);
int			main(int ac, char **av);

#endif
