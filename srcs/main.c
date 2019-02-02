/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:33:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/02 12:15:03 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*int 	ft_ls_R(char *input)
{
	DIR			*pDir;
	t_dirent	*pDirent;

	if ((pDir = opendir(input)) == NULL)
	{
		perror("ERROR");
		return (1);
	}
	while ((pDirent = readdir(pDir)))
	{
		if (pDirent->d_type == 4)
		{
			if (ft_strcmp(pDirent->d_name, ".") && ft_strcmp(pDirent->d_name, ".."))
			{
				ft_printf(BLU"\n\n%s/\n"NRM, pDirent->d_name);
				ft_ls_R(pDirent->d_name);
			}
		}
		else if (pDirent->d_type == 8)
			ft_printf("%s ", pDirent->d_name);
	}
	closedir(pDir);
	return (0);
}*/

int		main(int ac, char **av)
{
	t_datas datas;
	int		ret;

	ret = 1;
	// 1. parse les fichers
	// 2. parse les flags
	// 3. afficher les fichers
	ret = parse_flags(ac, av, &datas);
	parse_files(ac, av, &datas, ret);
	display_basic(datas);
	//show_result(&datas);
	return (0);
}
