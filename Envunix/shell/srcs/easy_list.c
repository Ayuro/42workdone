/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:08:31 by flemaist          #+#    #+#             */
/*   Updated: 2017/01/13 14:08:31 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/edit_line.h"

static void		add_path(t_word *files, char *path)
{
	char	*tmp;

	if (path && path[ft_strlen(path) - 1] != '/')
	{
		tmp = path;
		path = ft_strjoin(path, "/");
	}
	while (files)
	{
		tmp = files->word;
		files->word = ft_strjoin(path, files->word);
		free(tmp);
		files = files->next;
	}
}

size_t			nb_word(void *word)
{
	t_word		*list;
	size_t		i;

	i = 0;
	list = word;
	while (list)
	{
		list = list->next;
		i++;
	}
	free(list);
	return (i);
}

char			*get_name(char *path, char *new_name)
{
	char		*tmp;
	char		*ret;

	tmp = NULL;
	if (path && path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		ret = ft_strjoin(tmp, new_name);
		free(tmp);
		return (ret);
	}
	free(tmp);
	return (path ? ft_strjoin(path, new_name) : NULL);
}

t_word			*get_files(char *path)
{
	DIR				*folder;
	struct dirent	*file;
	t_word			*word;

	if (!(folder = opendir(path)))
		return (NULL);
	word = NULL;
	while ((file = readdir(folder)) && file->d_name[0] == '.')
		;
	if (file)
	{
		word = ft_memalloc(sizeof(t_word));
		word->word = ft_strdup(file->d_name);
	}
	while ((file = readdir(folder)))
		push_in_file(file, &word);
	closedir(folder);
	return (word);
}

int				get_files_recu(t_word *folder)
{
	DIR		*new_fold;
	t_word	*tmp;

	while (folder)
	{
		if ((new_fold = opendir(folder->word)))
		{
			closedir(new_fold);
			tmp = folder;
			while (folder->next)
				folder = folder->next;
			folder->next = get_files(tmp->word);
			add_path(folder->next, tmp->word);
			folder = tmp;
		}
		folder = folder->next;
	}
	free(tmp);
	return (1);
}
