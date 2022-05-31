/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:23:35 by ojauregu          #+#    #+#             */
/*   Updated: 2022/05/31 17:53:05 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

char *casser_la_pipe(t_mimi *shell)
{
	char	*str;
	char	buf[2];
	char	*temp;
	
	str = (char *)malloc(sizeof(char) * 1);//cree str
	str[0] = '\0';
	if (!str)
		return (NULL);
	shell->x = 0;
	while (str[shell->x] != '\0')
		shell->x++;
//	printf("x = %d\n",shell->x);
	while (/*str[shell->x] != '|' && */str[shell->x] != '\n')//ne fonctionne pas si on recoit des guillemets
	{
		shell->x = 0;
		while (str[shell->x] != '\0')
			shell->x++;
		read(0, buf, SIZE);// read de taille SIZE, 0 = fd donc sortie standard
		buf[1] = '\0';
	//	printf("wtf = %s\n", buf);
		temp = (char *)malloc(sizeof(char) * (shell->x + SIZE + 1));
		if (!temp)
			return (NULL);
		shell->x = -1;
		while (str[++shell->x] != '\0')
			temp[shell->x] = str[shell->x];
		temp[shell->x] = buf[0];
//	printf("overflow%d\n", shell->x);
		temp[shell->x + 1] = '\0';
		free(str);
		str = temp;
//shell->y++;
	//	printf("rerer '%s'\n", shell->line);
	//	printf("x = %d\n",shell->x);
	}
//	printf("test\n");
	return (str);
}

int	bye_bye(t_mimi *shell)//return last value executed | 0 if nothing done
{
	if (shell->pipe > 1)
	{
		if (shell->line[0] == 'e' && shell->line[1] == 'x' && shell->line[2] == 'i' && shell->line[3] == 't' && shell->line[4] == '\0')
			return (0);
	}
	return (0);
}

int	quote(t_mimi *shell)
{
	shell->len = 0;
	return (0);
}

int	parser(t_mimi *shell)//cree un tableau avec les arguments recus et return la foncion a utiliser (ls, cat etc)
{
	
	quote(shell);
	bye_bye(shell);//write exit et quit
	return (0);
}

int	init_mimi(t_mimi *shell)
{
	shell->pipe = 0;
	return (0);
}

int	main(/*int ac, char **av*/void)
{
	t_mimi	shell;

	shell.end = -1;
//shell.y = 0;
	while (shell.end == -1/* && shell.y < 25*/)
	{
		init_mimi(&shell);//reinitialise la structure a chaque debut 			
		while (shell.line[shell.len] != '\n')
		{
			shell.line = casser_la_pipe(&shell);//jusqua la prochaine pipe
		//fonction de repartition
			parser(&shell);
			printf("line= -->%s<--\n", shell.line);
		}
	//	if (shell.line == "exit\n")
	//		return (0);
//	shell.y++;
		free(shell.line);
	}
	return (0);
}
