/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/30 18:17:44 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/30 18:17:45 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

/*
*** INCLUDES
*/

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

/*
*** STRUCT & PROTO
*/

typedef	struct			s_list
{
	int					val;
	struct s_list		*next;
}						t_list;

/*
** Start
*/

void					ft_pushswap(char **av);

/*
** Create list & Memalloc
*/

void					ft_fill_list(t_list **l_a, char **av);
t_list					*ft_create_elem(t_list *l_a, char *av);

/*
** Parser
*/

int						ft_parse_list(t_list *l_a);

/*
** Modif on list
*/

void					ft_swap_list(t_list **l_a, t_list **l_b);
t_list					*ft_find_min(t_list **l_a);
int						ft_get_status(t_list **l_a, t_list *min);
void					ft_rotate_ltf(t_list **begin, const char *str);
void					ft_rotate_ftl(t_list **begin, const char *str);
void					ft_push(t_list **take, t_list **push, const char *str);
void					ft_swap(t_list **begin, const char *str);

#endif
