#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
/*
	Pour compiler :
	
	cc -Wall -Wextra -Werror -lreadline -fsanitize=address -g3 remi.c

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

char	*piece_of_string(char *str, int deb, int fin)//
{
	char	*tmp;
	int	x;

	x = 0;
	tmp = (char *)malloc(sizeof(char) * (fin - deb + 1));
	if (!tmp)
		return (NULL);
	while (deb + x < fin)
	{
		tmp[x] = str[deb + x];
		x++;
	}
	tmp[x] = '\0';
	return(tmp);
}

int	where_is_charly(char *str, int deb, char c)//get a string, a starting point, and a char, return an ending point
{
//	int	x;

//	x = 0;
	while (str[/*x*/deb] != c && str[deb] != '\0')
		deb/*x*/++;
	return (deb/*x*/);
}

int	parse(t_mimi *shell)
{
	int	x;

	x = 0;
	while (shell->line[x] != '\0')
	{
		
		x++;
	}
	return (0);	
}

int	main(/*int ac, char **av*/)
{
//	char	*line;
	t_mimi	shell;
	int	x;

	while (1)
	{
		x = 0;
		shell.line = readline("🐚mimishell🐚");
		if (!shell.line)
			return (0);
		add_history(shell.line);
	//	shell.ret_line = parse(&shell);
		printf("%s\n", shell.line);

	//	where_is_charly(shell.line, x, '|');
		while (shell.line[x] != '\0')
		{
			while (shell.line[x] == ' ')
				x++;
			shell.command = piece_of_string(shell.line, x, where_is_charly(shell.line, x, ' '));
			x = where_is_charly(shell.line, x, ' ');
			while (shell.line[x] == ' ')
				x++;
			shell.str = piece_of_string(shell.line, x, where_is_charly(shell.line, x, '|'));
			x = where_is_charly(shell.line, x, '|');
			printf("'%s' : '%s'\n", shell.command, shell.str);
			if (shell.line[x] == '|')
				x++;
			printf("=====> next_step here <=====\n");///////////////////////////////////////////////////////////
/*

		=======> Next step here <======			

 
*/		}
		free(shell.line);
		shell.line = NULL;
	}
	return (0);
}
