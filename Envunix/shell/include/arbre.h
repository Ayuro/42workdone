/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arbre.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdiridol <vdiridol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 19:28:19 by vdiridol          #+#    #+#             */
/*   Updated: 2016/06/21 19:28:19 by vdiridol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARBRE_H
# define ARBRE_H
# define _GNU_SOURCE
# define L 0
# define S 1
# define R 2
# define SS 3

# include "edit_line.h"

typedef struct	s_dt
{
	int			p[5];
	int			available;
	int			check;
}				t_dt;

void			completion_tree(t_arbre *a, char **mot, int i);
t_arbre			*alloue_noeud(unsigned char val, t_arbre *fg, t_arbre *fd);
int				ajoute_mot(t_arbre **a, char *str);
int				afficher_alphabetique(t_arbre **a);
int				afficher_mot(t_arbre *a, char *buf, int indice);
int				afficher_chemin(t_arbre *a, char *buf, int indice);
int				creer_arbre(t_arbre **a, char *name);
void			free_arbre(t_arbre **a);
t_arbre			*recherche(t_arbre **a, char *mot);

#endif
