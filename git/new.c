//#include "mimi.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
	recupere info en ligne de commande 
	parse un pipe
	renvoie,
	le rezsultat est stocke dans a struct
	etc jusqua \n
	reset dans le struct


include errno.h
ne gere aue les appels system

__FILE__ __LINE__
voir assert (programme crash when param wrong)

fonctiona a coder:
	+ (char *str, int deb, int fin) recoit un char * et deux int, un debut une fin, renvoie un char * qui contient les char entre le debut et la fin malloc.
	+ where_is_charly(char *str, int deb, char c) recoit un char * un int de debut et un char, cherche le prochain char identique et renvoie un int de sa position
	+ 

*/

/*echo
export
env
exit

cd
pwd

unset
*/

typedef struct	s_mimi
{
		int	run;//tant que run est suppérieur à 0 ca tourne, si run inf a 0 return erreur, si run == 0 == fin
		char	***str;
		char	*line;
		char	*command;
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

/*int	where_is_charly(char *str, int deb, char c)//get a string, a starting point, and a char, return an ending point
{
	int	x;

	x = 0;
	while (str[x] != c)
		x++;
	return (x);
}*/

char	*put_string_in(char *from, int x, char delim)
{
	int	y;

	char	*str;

	y = 0;
	while (from[x + y] != delim)
		y++;
	str = (char *)malloc(sizeof(char) * (y + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (from[x + y] != delim)
	{
		str[y] = from[x + y];
		y++;
	}
	str[y] = '\0';
	return (str);
}

int	go_next(t_mimi *shell, int x, char *str)
{
	int	y;
	char	*tmp;

	y = 0;
	shell->command = str;
	while (shell->line[x] == ' ')
		x++;
	while (shell->line[x + y] != '|' && shell->line[x + y] != '\n')
		y++;
	while (shell->line[x + --y] == ' ')
		y--;//a voir si ca tourne avec ca
	tmp = (char *)malloc(sizeof(char) * (y + 1));
	if (!tmp)
		return (-1);
	y = 0;
	while (shell->line[x + y] != '|' && shell->line[x + y] != '\n')
	{
		tmp[y] = shell->line[x + y];
		y++;
	}
	return (x);
}
/*
int	get_command(t_mimi *shell, int x)
{
	int	comp;

//	comp = compare(shell->line, x, "cd ");
	if (comp != -1)
	{
		x = go_next(shell, x, "cd");		
	}
	return (x);
}
*//*
int	casser_sa_pipe(t_mimi *shell)
{
	int	x;

	x = 0;
	while (shell->line[x] != '\0')
	{
		while (shell->line[x] == ' ')
			x++;
		get_command(shell, x);
//		if (shell->line[x] == )
			
		x++;
	}
	return (0);
}
*/
void	print_tab(t_mimi *shell)
{
	int	y, x;
	printf("	Tab de char ici :\n");
	printf("\n");
	y = 0;
	printf("Col |  Arguments  |\n");
	while (y < shell->y)
	{
		x = 0;
		printf(" %d  ", y);
		while (x < shell->x)
		{
			printf("| %s ", shell->str[y][x]);
			x++;
		}
		printf("|\n");
		printf("----------------------------------\n");
		y++;
	}
	printf("	Fin tab de char.\n");

	printf("Exemple pour accéder à un char: ici %c dans le tableau\n", shell->str[1][2][8]);//acces a char

	/*	shell->str = (char **)malloc(sizeof(char  **) * (1));
		if (shell->str == NULL)
		return (-1);
		shell->str[0] = (char **)malloc(sizeof(char  *7 *) * (1));
		if (shell->str == NULL)
		return (-1);
		shell->str[0][0] = (char **)malloc(sizeof(char *));//malloc les
		if (shell->str[0][0] == NULL)
		return (-1);
	 */

//	return (0);
}

void	free_tab(t_mimi *shell)
{
	int	y, x;
	printf("	Tab FREE ici :\n");
	printf("\n");
	y = 0;
	while (y < shell->y)
	{
		x = 0;
		while (x < shell->x)
		{
			free(shell->str[y][x]);
			x++;
		}
		free(shell->str[y]);
		y++;
	}
	free(shell->str);
	printf("fn de free\n");//
}

int     str_len(char *str)
{
        int     x;

        x = 0;
        while (str[x] != '\0')
                x++;
        return (x);
}

char    *till_the_n(t_mimi *shell)
{
        char    buf[2];
        char    *temp;
        char    *str;
        int             x;

        x = 0;
   //   printf("till the n \n");////
        str = (char *)malloc(sizeof(char) * 1);
        str[0] = '\0';
        if (!str)
                return (NULL);
        while (str[x] != '\n')
        {
                read(0, buf, 1);
                buf[1] = '\0';
                x = str_len(str);
                temp = (char *)malloc(sizeof(char) * (x + 2));
                if (!temp)
                        return(NULL);
                x = 0;
                while (str[x] != '\0')
                {
                        temp[x] = str[x];
                        x++;
                }
                temp[x] = buf[0];
                temp[x + 1] = '\0';
               // free(str);
                str = temp;
        }
        shell->run++;
//      printf("end the n \n");///
        return (str);
}

int	putin_tab(char *str, t_mimi *shell)
{
	int	pipe;
	int	x;
	int	y;

	x = 0;
	pipe = 0;
//	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	while (str[x] != '\0')
	{
		if (str[x] == '|')
			pipe++;
		x++;
	}
	y = 0;
	while (y < pipe)
	{
		//free(shell->str[y]);
		shell->str[y] = (char **)malloc(sizeof(char *) * ((pipe * x) + 1));//malloc les col
		if (shell->str[y] == NULL)
			return (-1);
		y++;
	}
	shell->y = 2;
	shell->x = pipe;
	shell->z = 250;

	x = 0;
	pipe = 0;
	while (str[x] != '\0')
	{
		y = 0;
		while (str[x] == ' ')
			x++;
		while (str[x + y] != ' ' && str[x + y] != '\0')
			y++;
		//printf("new string: %s\n", shell->str[0][pipe]);////////
		//free(shell->str[0][pipe]);
		shell->str[0][pipe] = (char *)malloc(sizeof(char) * (y + 1));//malloc de la commande.
		if (shell->str[0][pipe] == NULL)
			return (-1);
		y = 0;
		while (str[x + y] != ' ' && str[x + y] != '\0')
		{
			shell->str[0][pipe][y] = str[x + y];
			y++;
		}
		x = x + y;
		y = 0;
		while (str[x] == ' ')
			x++;
		while (str[x + y] != '|' && str[x + y] != '\0')
			y++;
	//	free(shell->str[1][pipe]);
		shell->str[1][pipe]= (char *)malloc(sizeof(char) * (y + 1));//malloc de la commande.
		if (shell->str[1][pipe] == NULL)
			return (-1);
		while (str[x + y] != ' ' && str[x + y] != '\0')
		{
			shell->str[1][pipe][y] = str[x + y];
			y++;
		}

		pipe++;

	}
/*	malloc size de y	
		free old stuff et put str in it in place 0
		idem for place 1 (args)*/	
	return (0);
}

/*int	semi_parse_tab(t_mimi *shell)
{
	int	x;

	while (shell->line[x] != '\0')
	{
		if ()
	}
	return (0);
}*/

int	alloc_tab(t_mimi *shell)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	shell->str = (char ***)malloc(sizeof(char **) * (shell->y * shell->x * shell->z));
	if (shell->str == NULL)
		return (-1);///
	while (y < shell->y)
	{
		shell->str[y] = (char **)malloc(sizeof(char *) * (shell->x * shell->z));//malloc les col
		if (shell->str[y] == NULL)
			return (-1);///
		while (x < shell->x)
		{
			shell->str[y][x] = (char *)malloc(sizeof(char) * (shell->z));//malloc les futures strings.
			if (shell->str[y][x] == NULL)
				return (-1);///
			x++;
		}

		y++;
	}
	return (0);
}


int	struct_init(t_mimi *shell)
{
	int	size_y = 2;
	int	size_x = 3;
	int	size_z = 10;
//	int	x = 0;
//	int	y = 0;

	shell->y = size_y;
	shell->x = size_x;
	shell->z = size_z;
	shell->run = 1;
/*	shell->str = (char ***)malloc(sizeof(char **) * (size_y * size_x * size_z));
	if (shell->str == NULL)
		return (-1);
	while (y < size_y)
	{
		shell->str[y] = (char **)malloc(sizeof(char *) * (size_x * size_z));//malloc les col
		if (shell->str[y] == NULL)
			return (-1);
		while (x < size_x)
		{
			shell->str[y][x] = (char *)malloc(sizeof(char) * (size_z));//malloc les futures strings.
			if (shell->str[y][x] == NULL)
				return (-1);
			x++;
		}

		y++;
	}*/
//	printf("fin des allocs de colonnes\n");
	/*	while (x < size_x)
		{
		shell->str[y][x] = (char *)malloc(sizeof(char) * (size_z));//malloc les futures strings.
		if (shell->str[y][x] == NULL)
		return (-1);
		x++;
		}*/
//	printf("fin des allocs des lignes\n");
	//	shell->str[0][0] = "colA";	
	//	shell->str[1][0] = "colB";
	//	printf("col AB\n");	
	shell->str[0][0] = "ligne1A";	
	shell->str[0][1] = "ligne2A";	
	shell->str[0][2] = "ligne3A";	
	shell->str[1][0] = "ligne1B";	
	shell->str[1][1] = "ligne2B";	
	shell->str[1][2] = "ligne3B X";
	printf("fin des textes\n");
	//	shell->str[0][0] = "col1";	
	//	shell->str[0][0] = "col1";
	print_tab(shell);
	return (0);
}	

/*
void	printf_tab(t_mimi *shell)
{
	printf("	Tab se char ici :\n");
	printf("\n");
	y = 0;
	printf("Col |  Arguments  |\n");
	while (y < size_y)
	{
		x = 0;
		printf(" %d  ", y);
		while (x < size_x)
		{
			printf("| %s ", shell->str[y][x]);
			x++;
		}
		printf("|\n");
		printf("----------------------------------\n");
		y++;
	}
	printf("	Fin tab de char.\n");

	printf("Exemple pour accéder à un char: ici %c dans le tableau\n", shell->str[1][2][8]);//acces a char

	shell->str = (char **)malloc(sizeof(char  **) * (1));
		if (shell->str == NULL)
		return (-1);
		shell->str[0] = (char **)malloc(sizeof(char  *7 *) * (1));
		if (shell->str == NULL)
		return (-1);
		shell->str[0][0] = (char **)malloc(sizeof(char *));//malloc les
		if (shell->str[0][0] == NULL)
		return (-1);
	 

//	return (0);
}
*/
int	main(int ac, char **av)
{
	(void)av;
	t_mimi	shell;

	if (ac != 1)
	{
		printf("Error: starting suppose no arguments\n");//
		return (-1);
	}
	struct_init(&shell);
	while (shell.run > 0)
	{
		shell.line = till_the_n(&shell);
		printf("line = %s\n", shell.line);
		
	//	free_tab(&shell);
		printf("sortie\n");
		putin_tab(shell.line, &shell);
		print_tab(&shell);
		free_tab(&shell);
		free(shell.line);//??
	}
	return (0);
}
