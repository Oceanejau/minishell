NAME = minishell

BONUS = minishell_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

SRCS = srcs/.c\

BONUS = bonus/.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.c)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SILENT:
