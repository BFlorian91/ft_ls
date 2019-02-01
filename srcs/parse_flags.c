/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:20:53 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 21:14:51 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parse_flags(int ac, char **av, t_datas *datas)
{
	int		i;
	int		j;
	int		k;
	int		ret;

	k = 0;
	i = 1;
	ret = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			ret++;
			while (av[i][j] && k < 254)
				datas->flags[k++] = av[i][j++];
		}
		i++;
	}
	datas->flags[k] = '\0';
	return (ret);
}
