#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define	PHILO_MAX 5

typedef struct	s_stru
{
	int	nb;
	int	feed;
	int	left;
	int	right;
	
}		t_stru;

typedef struct	s_big
{
	int philo;
	int	x;
	int	it;
	int	zzz;
	int	think;
	int	food;
	
	pthread_mutex_t	fork[PHILO_MAX];
	t_stru	stru[PHILO_MAX];
}		t_big;

void	*routine(void *mac)
{
//	printf("entre\n");
	t_big	*re_mac;
//	t_stru	*stru;
	int	philo;	

	re_mac = (t_big *)mac;
	philo = re_mac->x;
//	stru = re_mac->stru[re_mac->x];
//	printf("x = %d\n", re_mac->x);
	printf("i am philo : %d\n", re_mac->stru[re_mac->x].nb);
//	printf("try it: %d\n", stru[re_mac->x].nb);
//	if (re_mac[philo])	
	if (re_mac->stru->left == 0)
	{
		pthread_mutex_lock(&re_mac->fork[philo]);
	//	printf("eat\n");
		pthread_mutex_lock(&re_mac->fork[philo - 1]);
		usleep(re_mac->food);
		printf("eat %d\n", re_mac->x);
		re_mac->stru[philo].feed++;
	}
	pthread_mutex_unlock(&(re_mac->fork[philo]));

	pthread_mutex_unlock(&(re_mac->fork[philo - 1]));

//	re->nb*=2;
//	usleep(100);
//`	if (re->nb > 20)
//		pthread
	return (NULL);
}

int main()
{
	t_big	mac;
	pthread_t	thread[PHILO_MAX];
	int x;
	int	y;

	x = 0;
	y = 0;
	mac.philo = 5;
	mac.zzz = 2;
	mac.it =  30;
	mac.food = 10;
	mac.think = 1;
	while (x < 5)
	{
		mac.stru[x].nb = x;
	//	printf("mac nb = %d\n", mac.stru[x].nb);
		mac.stru[x].left = 0;
		mac.stru[x].right = 0;
		pthread_mutex_init(&mac.fork[x], NULL);
		x++;
	}
	x = 0;
//	printf("start\n");
	while (y < mac.it)
	{
		while (x < mac.philo)
		{
		//	printf("y = %d, x = %d\n", y, x);
			mac.x = x;
			if (pthread_create(&(thread[x]), NULL, routine, &(mac)) != 0)
				return (-1);
			x++;
			usleep(1);
	//		printf("next thread\n");
		}
		x = 0;
		y++;
	}
	printf("y= %d", y);
	while (x < 5)
	{
		pthread_join(thread[x], NULL);
		x++;
	}
//	printf("fin\n");	
	return (-1);
}
