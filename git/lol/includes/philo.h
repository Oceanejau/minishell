/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:56:59 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/09 23:05:42 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_soph;

typedef struct s_hales
{
	int					who;
	int					eat;
	int					l_fork;
	int					r_fork;
	long long			t_eat;
	struct s_soph		*soph;
	pthread_t			thread_who;
}						t_hales;

typedef struct s_soph
{
	int					nb_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					nb_eat;
	int					died;
	int					all;
	long long			first_t;
	pthread_mutex_t		meal_check;
	pthread_mutex_t		fork[300];
	pthread_mutex_t		scribe;
	t_hales				thales[300];
}						t_soph;

void		print_it(t_soph *soph, int x, char *str);
void		counting_sheep(long long time, t_soph *soph);
long long	timer(long long past, long long pres);
long long	timestamp_in_ms(void);
int			philo(t_soph *soph);
void		pissenlit(t_soph *soph, t_hales *p, int x);
void		racine(t_soph *soph, t_hales *philos);
void		*p_thread(void *void_philosopher);
void		festin(t_hales *philo);
int			starter(t_soph *soph, char **av);
int			philo_thales(t_soph *soph);
int			init_mutex(t_soph *soph);
int			err(int error);
int			write_error(char *str, int x);
int			ft_atoi(const char *str);
int			main(int ac, char **av);

#endif
