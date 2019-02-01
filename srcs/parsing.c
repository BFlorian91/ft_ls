/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:21:08 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/01 15:21:44 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* func de test if is a folder */

/* func de test file */

int		parsing(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		ft_printf("DEBUG_1\n");
		if (av[i][1] == '-' && av[i][2])
			return (i + 1);
		if (!check_opt(av[i]))
			return (-1);
	}
	return (0);
}
