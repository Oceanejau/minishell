#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
/*
	Pour compiler :
	
	cc -Wall -Wextra -Werror -lreadline -fsanitize=address -g3 mimi.c

		!! warning still reachable with valgrind
*/

typedef struct	s_mimi
{
		int	run;//tant que run est suppérieur à 0 ca tourne, si run inf a 0 return erreur, si run == 0 == fin
	//	char	***str;
		char	*line;
		char	*command;
		char	*str;
		char	*args;
		int	ret_line;
		int	end;
		int	y;//pipes
		int	x;//nb d'args a placer
		int	z;//nb char a placer



}		t_mimi;




char	*piece_of_string(char *str, int deb, int fin);//

int	where_is_charly(char *str, int deb, char c);//get a string, a starting point, and a char, return an ending point
int	parse(t_mimi *shell);
int	main(/*int ac, char **av*/);

