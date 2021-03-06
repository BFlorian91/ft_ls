/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 10:53:13 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/04 19:25:58 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int		parse_flags(int ac, char **av, t_data *data)
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
				data->flags[k++] = av[i][j++];
		}
		i++;
	}
	data->flags[k] = '\0';
	return (ret);
}
