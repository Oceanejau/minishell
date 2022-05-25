#include "minishell.h"
//#include "../includes/minishell.h"

int	str_len(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*till_the_n(t_mimi *shell)
{
	char	buf[2];
	char	*temp;
	char	*str;
	int		x;

	x = 0;
	//	printf("till the n \n");////
	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	if (!str)
		return (NULL);
	while (str[x] != '\n')
	{
		read(0, buf, 1);
		buf[1] = '\0';
		x = str_len(str);
		temp = (char *)malloc(sizeof(char) * (x + 1));
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
		free(str);
		str = temp;
	}
	shell->end++;
	//	printf("end the n \n");///
	return (str);
}

char	*gnl(t_mimi *shell)
{
	if (!shell->str)
	{
		shell->str = (char *)malloc(sizeof(char) * 1);
		if (!shell->str)
			return (NULL);
		shell->str[0] = '\0';
	}
	//	while ()
	return (0);
}

void	ft_putchar(char c)//doit gerer la couleur d'affichage
{
	write(1, &c, 1);
	return ;
}

int	str_comp(char *str, char *comp)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	//	printf("comp\n");//
	while (str[x] != '\0')
	{
		if (str[x] == comp[y])
		{
			while (str[x + y] == comp[y])
				y++;
			if (comp[y] == '\0')
			{
				while (str[x + y] == ' ')
					y++;
				//	printf("x + y= %d\n", x + y);///
				return (x + y);//position du truc a prendre en consideration
			}
		}
		x++;
	}

	return (-1);
}


void	repartiteur(t_mimi *shell)
{
	shell->echon = str_comp(shell->line, "echo -n");
	shell->echo = str_comp(shell->line, "echo ");
	shell->end = str_comp(shell->line, "exit");
	shell->kitty = str_comp(shell->line, "cat");
	//	fonction qui repere les truc et renvoie un int qui correspond a la positin du truc a traiter dans la ligne
	if (shell->echon > -1)
		narcisse_and_co(shell);
	else if (shell->echo > -1)
		narcisse(shell);
	if (shell->end != -1)
		end(shell);
	if (shell->kitty != -1)
		kitty(shell);
	//	if ()
}

void	kitty(t_mimi *shell)
{
	int	x;

	while (shell->line[shell->kitty] == ' ')
		shell->kitty++;
	x = shell->kitty;
	while (shell->line[x] != ' ' || shell->line[x] != '\n')//
		x++;
	x = x - shell->kitty;
/*	malloc de size x;
	creee une string qui contient de kitty a x
		faire un open read du fichier du nom de la string//gerererreur de nom*/
		return ;
}

void	narcisse_and_co(t_mimi *shell)// manque les chars invisibles
{
	while (shell->line[shell->echon] != '\n')
	{
		ft_putchar(shell->line[shell->echon]);
		shell->echon++;
	}
	shell->echon = -1;
	return ;
}

void	narcisse(t_mimi *shell)
{
	//	printf("entre\n");//
	while (shell->line[shell->echo] != '\0')
	{
		ft_putchar(shell->line[shell->echo]);
		shell->echo++;
	}
	shell->echo = -1;
	return ;
}

int	end(t_mimi *shell)//doit quitter proprement, == exit
{
	shell->end = 0;
	return (shell->ret);//ret =  le ret precedant
}

//void	env(t_mimi )//print les variable de l'endroit en cours

/*void	b_jobs(t_mimi *shell)//pipes a voir comment organiser tout ca
  {
  return ;
  }*/

int	add_history(t_mimi *shell)
{
	int	x;
	int	y;
	char *tmp;

	x = 0;
	y = 0;
	//	printf("start history\n");/////
	while (shell->line[x] != '\0')
		x++;
	while (shell->history[x] != '\0')
		y++;
	//	printf("history midiiii\n");//
	tmp = (char *)malloc(sizeof(char) * (y + x + 1));
	if (!tmp)
		return (-1);
	x = 0;
	y = 0;
	//	printf("history mid\n");//
	while (shell->history[x] != '\0')
	{
		tmp[x] = shell->history[x];
		x++;
	}
	while (shell->line[y] != '\0')
	{
		tmp[x] = shell->line[y];
		x++;
		y++;
	}
	free(shell->history);
	shell->history = tmp;
	//	printf("end history\n");//
	return (0);
}

int	main(void)
{
	t_mimi	shell;

	//shell.n = 0;
	shell.end = -1;
	shell.history = (char *)malloc(sizeof(char) * (1));
	if (!shell.history)
		return (-1);
	shell.history[0] = '\0';
	//	open(0, O_RDONLY);
	//	printf("start\n");//
	while (shell.end == -1)
	{
		shell.line = till_the_n(&shell);
		//shell.echo = 0;
		//	printf("next\n");///

		//	repartiteur(&shell);
		shell.ret = add_history(&shell);//if -1 erreur a traiter
		repartiteur(&shell);
		free(shell.line);
		//	printf("history = %s", shell.history);/////
	}
	return (0)/*jusqu'au '\n' = get_next_line(fd = 0)*/;
	return (0);
}
