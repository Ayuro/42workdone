/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:08:47 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:08:48 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/edit_line.h"
#include "../include/minishell.h"

void	push_in_file(struct dirent *file, t_word **word)
{
	if (file && *word &&
		ft_strcmp(file->d_name, (*word)->word) < 0 && file->d_name[0] != '.')
		pushback(file->d_name, word);
	else if (file && file->d_name[0] != '.')
		push_front(file->d_name, *word);
}

void	clear_words(void *word)
{
	t_word	*tmp;
	t_word	*to_delete;

	to_delete = word;
	while (to_delete)
	{
		tmp = to_delete;
		to_delete = to_delete->next;
		free(tmp->word);
		free(tmp);
	}
	free(to_delete);
}

void	push_front(char *new_name, t_word *word)
{
	t_word		*new;

	new = ft_memalloc(sizeof(t_word));
	new->word = ft_strdup(new_name);
	while (word && word->next)
	{
		if (ft_strcmp(word->next->word, new_name) >= 0)
		{
			new->next = word->next;
			word->next = new;
			return ;
		}
		word = word->next;
	}
	word->next = new;
}

void	pushback(char *new_name, t_word **word)
{
	t_word	*new;

	new = ft_memalloc(sizeof(t_word));
	new->next = *word;
	*word = new;
	new->word = ft_strdup(new_name);
}
