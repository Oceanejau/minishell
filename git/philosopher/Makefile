NAME = 	philo

BONUS = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread
 
INCLUDES = ./includes

SRCS = srcs/philo.c\
	   srcs/ft_atoi.c\
	   srcs/ft_itoa.c\
	   srcs/ft_strlen.c\

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJS)

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
.SILENT:
