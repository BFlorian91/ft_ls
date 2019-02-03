/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:55:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 19:29:04 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	display_files(t_datas datas)
{
	t_list	*files;
	t_file	*file;

	files = datas.files;
	while (files)
	{
		file = files->content;
		ft_printf("%s", file->name);
		if (files->next == NULL)
			printf("\n\n");
		else
			ft_printf("\t");
		files = files->next;
	}
	return (0);
}

static int	display_folder(t_datas datas, int ac)
{
	t_list	*dirs;
	t_dir	*dir;
	t_file	*file;

	dirs = datas.dirs;
	while (dirs)
	{
		dir = dirs->content;
		if (ac >= 2)
			ft_printf(BLU"%s:\n"NRM, dir->name);
		while (dir->files)
		{
			file = dir->files->content;
			ft_printf("%s", file->name);
			if (dir->files->next == NULL)
				ft_printf("\n\n");
			else
				ft_printf("\t");
			dir->files = dir->files->next;
		}
		dirs = dirs->next;
	}
	return (0);
}

int			main_display(int ac, char **av)
{
	t_datas datas;
	int		ret;

	ret = 1;
	datas.files = NULL;
	ret = parse_flags(ac, av, &datas);
	parse_files(ac, av, &datas, ret);
	display_files(datas);
	display_folder(datas, ac);
	return (0);
}
