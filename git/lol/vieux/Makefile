NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread

INCLUDES = ./includes/

SRCS = srcs/error.c\
		srcs/ft_atoi.c\
		srcs/mutex.c\
		srcs/pissenlit.c\
		srcs/p_thread.c\
		srcs/times.c\
		srcs/festin.c\
		srcs/main.c\
		srcs/philo.c\
		srcs/print_it.c\
		srcs/starter.c\
		srcs/counting_sheep.c\

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME) : $(OBJS) 
	@$(CC) $(CFLAGS) -fsanitize=thread -I $(INCLUDES) $(OBJS) -o $(NAME)
.c.o:
	 @$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

clean: 
	@rm -rf $(OBJS) 

fclean : clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
.SILENT:
