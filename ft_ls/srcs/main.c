/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:33:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/01 18:24:47 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int 	ft_ls_R(char *input)
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
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_ls_R(".");
	else if (ac == 3)
	{
		if ((ft_strcmp(av[1], "-R")) == 0)
			ft_ls_R(av[2]);
		else
			ft_printf("Error: usage ls -R `input` or ls -R ");
	}
	return (0);
}
