/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:15:10 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/22 15:20:52 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.size)
	{
		j = 0;
		while (j < map.size)
			ft_putchar(map.map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

void	clean_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
		free(map.map[i++]);
	free(map.map);
}

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	if ((map = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	map[size] = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		if ((map[i] = malloc(size + 1)) == NULL)
		{
			free(map);
			return (NULL);
		}
		map[i][size] = '\0';
		while (j <= size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}
