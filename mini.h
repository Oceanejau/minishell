/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojauregu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:23:25 by ojauregu          #+#    #+#             */
/*   Updated: 2022/05/31 18:26:16 by ojauregu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINI_H
# define MINI_H

# define SIZE 1//////taille du read pour les pipes

# include <stdio.h>////////////////
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_mimi
{
		int	end;// condition de fin de tout le process, tant que c'est egal a -1 ca tourne
		char	*line;//stock ce qui passe en parametre
		int	x;//un x
		int	pipe;
		int	len;
	//	int	y;
		
}		t_mimi;



int	init_mimi(t_mimi *shell);
int	bye_bye(t_mimi *shell);//put good exit
int	parser(t_mimi *shell);
int	quote(t_mimi *shell);
char	*casser_la_pipe(t_mimi *shell);
int	main(/*int ac, char **av*/void);

#endif


/*

 cc -Wall -Wextra -Werror -fsanitize=address mini_main.c && ./a.out


Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non
demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).

’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets.

" (double quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets sauf le $ (signe dollar).

< doit rediriger l’entrée.

> doit rediriger la sortie.

<< doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne
contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !

>> doit rediriger la sortie en mode append

| pipe a implemnter

$ variables d’environnement a gerer

$? qui doit être substitué par le statut de sortie de la dernière pipeline
exécutée au premier plan

ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash.
ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
ctrl-D quitte le shell.
ctrl-\ ne fait rien.

echo et l’option -n
cd uniquement avec un chemin relatif ou absolu
pwd sans aucune option
export sans aucune option
unset sans aucune option
env sans aucune option ni argument
exit sans aucune option

===============BONUS================
&& et || avec des parenthèses pour les priorités.
Les wildcards * doivent fonctionner pour le répertoire courant
*/
