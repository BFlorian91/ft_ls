/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:55:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 23:05:15 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	hide_point(char *str, t_datas datas)
{
	if (!(ft_strstr(datas.flags, "a")))
		if (!ft_strncmp(str, ".", 1))
			return (1);
	return (0);
}

static int	display_files(t_datas datas)
{
	t_list	*files;
	t_file	*file;

	files = datas.files;
	while (files)
	{
		file = files->content;
		if (!(hide_point(file->name, datas)))
		{
			ft_printf("%s", file->name);
			if (files->next == NULL)
				ft_printf("\n");
			else
				ft_printf(" ");
		}
		files = files->next;
	}
	return (0);
}

static int	display_folder(t_datas datas, int ac)
{
	t_list	*dirs;
	t_dir	*dir;
	t_file	*file;
	int		i;

	dirs = datas.dirs;
	i = 0;
	while (dirs)
	{
		dir = dirs->content;
		if ((((ac > 2) && (ac != 3 && ft_strstr(datas.flags, "R"))) 
			|| i++ != 0)) 						//  <=== BUG HERE
			ft_printf(BLU"%s:\n"NRM, dir->name);
		while (dir->files)
		{
			file = dir->files->content;	
			if (!(hide_point(file->name, datas)))
			{
				ft_printf("%-15s", file->name);
				if (dir->files->next == NULL)
					ft_printf("\n\n");
				else
					ft_printf("\t");
			}
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
