/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:43:58 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/16 19:44:02 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map && *map)
	{
		while (i < size)
		{
			j = 0;
			while (j < size)
				ft_putchar(map[i][j++]);
			ft_putchar('\n');
			i++;
		}
	}
}

char	**resize_map(char **map, int size)
{
	char	**new_map;
	int		i;

	new_map = NULL;
	i = 0;
	if (map && *map)
	{
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		if ((new_map = create_map(size)) == NULL)
			return (NULL);
	}
	return (new_map);
}

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	map[size] = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		map[i] = malloc(size + 1);
		map[i][size] = '\0';
		while (j <= size)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}
