/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:51:41 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/02 12:17:06 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	add_dir(char *str, t_datas *datas)
{
	t_list *new;

	new = ft_lstnew(str, sizeof(str));
	new->next = datas->dirs;
	datas->dirs = new;
	return (0);
}

static int	add_file(char *str, t_datas *datas)
{
	t_list *new;

	new = ft_lstnew(str, sizeof(str));
	new->next = datas->files;
	datas->files = new;
	return (0);
}

int		parse_files(int ac, char **av, t_datas *datas, int i)
{
	int			j;
	int			k;
	struct stat	s;
	char		*error;

	k = 0;
	while (i < ac)
	{
		if (stat(av[i], &s) == 0)
		{
			j = 0;
			if (s.st_mode & S_IFDIR)
				add_dir(av[i], datas);
			if (s.st_mode &  S_IFREG)
				add_file(av[i], datas);
		}
		else
		{
			perror((error = ft_strjoin("ls: ", av[i])));
			free(error);
		}
				
		i++;
	}
	datas->flags[k] = '\0';
	return (0);
}
