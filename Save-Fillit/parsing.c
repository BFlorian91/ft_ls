/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:00:02 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/13 20:33:28 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_point(t_tri *new_element, char *buffer)
{
	int	i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (buffer[j++] != '#')
		i++;
	j = 0;
	while (buffer[j])
	{
		if (buffer[j] == '#')
		{
			new_element->pos[nb].x = (j % 5) - (i % 5);
			new_element->pos[nb].y = (j / 5) - (i / 5);
			nb++;
		}
		j++;
	}
}

static t_tri	*new_tetri(t_tri *lst_tetri, char *buffer, char c)
{
	t_tri	*first;
	t_tri	*new_element;

	first = lst_tetri;
	if ((new_element = (t_tri *)malloc(sizeof(t_tri))) == NULL)
		return (NULL);
	if (lst_tetri)
	{
		while (lst_tetri->next)
			lst_tetri = lst_tetri->next;
		lst_tetri->next = new_element;
	}
	new_element->c = c;
	new_element->next = NULL;
	set_point(new_element, buffer);
	if (first == NULL)
		return (new_element);
	return (first);
}

t_tri			*parse(char *av)
{
	t_tri	*lst_tetri;
	int		fd;
	int		ret;
	char	buffer[21];
	char	c;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	c = 'A';
	lst_tetri = NULL;
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[ret] = '\0';
		lst_tetri = new_tetri(lst_tetri, buffer, c);
		c++;
	}
	close(fd);
	return (lst_tetri);
}
