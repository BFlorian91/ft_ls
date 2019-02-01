/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:18:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/01 19:31:57 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_opt(char *av)
{
	struct s_opt opt;

	if (ft_strchr(av[1], "l"))
		opt.l = 1;
	if (ft_strchr(av[1], "R"))
		opt.up_r = 1;
	if (ft_strchr(av[1], "a"))
		opt.a = 1;
	if (ft_strchr(av[1], "r"))
		opt.r = 1;
	if (ft_strchr(av[1], "t"))
		opt.t = 1;
}

int		check_type(struct dirent *pDirent, DIR *pDir, int ac, char **av)
{
	pDir = opendir(av[1]);
	(void)ac;
	while ((pDirent = readdir(pDir)))
	{
	ft_printf("DEBUGGG!!!\n");
		if (pDirent->d_type == 4)
		{
			ft_printf("%-30stest", "It's a directory");
			return (1);
		}
	}
	closedir(pDir);
	return (0);
}
