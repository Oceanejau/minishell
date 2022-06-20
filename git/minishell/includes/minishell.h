/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:38:55 by ojauregu          #+#    #+#             */
/*   Updated: 2022/04/13 17:24:13 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>//////

typedef struct	s_mimi
{
				char	*line;
				char	*str;
				char	*history;
				int		end;
				int		ret;
				int		echo;
				int		echon;
}				t_mimi;

void	end(t_mimi *shell);
void	ft_putchar(char c);
int	str_len(char *str);
void	repartiteur(t_mimi*shell);
void	narcisse_and_co(t_mimi *shell);
void	narcisse(t_mimi *shell);
char *till_the_n(t_mimi *shell);
char *gnl(t_mimi *shell);
int	main(void);

#endif
