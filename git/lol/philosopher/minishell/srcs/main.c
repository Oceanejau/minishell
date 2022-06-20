/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:36:07 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/10 04:30:40 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	till_the_n(t_mimi shell, int fd)
{
	char	*buf;
	int		n;

	n = 0;
	while (n == 0)
	{
		read(0, buf, 1);
		if ()
	}
}

char	*gnl(int fd, t_mimi shell)
{
	if (!shell->str)
	{
		shell->str = (char *)malloc(sizeof(char) * 1);
		if (!shell->str)
			return (NULL);
		shell->str[0] = '\0';
	}
	while ()
	return ();
}

int	main(void)
{
	t_mimi	shell;

	open(0, O_RDONLY);
	while (shell.line != NULL)
	{
		shell.line = gnl(0, &shell);
	}
	return jusqu'au '\n' = get_next_line(fd = 0);
	return (0);
}
