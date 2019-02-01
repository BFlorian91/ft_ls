/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:47:40 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/17 21:07:20 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_place(t_map map, t_tri *minos, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (i + minos->pos[k].x < 0 || i + minos->pos[k].x >= map.size)
			return (0);
		if (j + minos->pos[k].y < 0 || j + minos->pos[k].y >= map.size)
			return (0);
		if (map.map[j + minos->pos[k].y][i + minos->pos[k].x] != '.')
			return (0);
		k++;
	}
	return (1);
}

static void	place_t(t_tri *lst, t_map map, int i, int j)
{
	map.map[j][i] = lst->c;
	map.map[j + lst->pos[1].y][i + lst->pos[1].x] = lst->c;
	map.map[j + lst->pos[2].y][i + lst->pos[2].x] = lst->c;
	map.map[j + lst->pos[3].y][i + lst->pos[3].x] = lst->c;
}

static void	remove_t(t_tri *lst, t_map map, int i, int j)
{
	map.map[j][i] = '.';
	map.map[j + lst->pos[1].y][i + lst->pos[1].x] = '.';
	map.map[j + lst->pos[2].y][i + lst->pos[2].x] = '.';
	map.map[j + lst->pos[3].y][i + lst->pos[3].x] = '.';
}

int			solving(t_tri *minos, t_map map, char c)
{
	int i;
	int j;

	j = 0;
	while (j < map.size)
	{
		i = 0;
		while (i < map.size)
		{
			if (can_place(map, minos, i, j))
			{
				place_t(minos, map, i, j);
				if (minos->next == NULL || solving(minos->next, map, c + 1))
					return (1);
				remove_t(minos, map, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
