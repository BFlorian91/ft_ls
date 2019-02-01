/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:49:11 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/22 15:14:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_root(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

static int	check_block(char *buf)
{
	int i;
	int dot;
	int sharp;
	int line;

	i = 0;
	dot = 0;
	sharp = 0;
	line = 0;
	while (i < 20)
	{
		buf[i] == '\n' ? line++ : line;
		buf[i] == '.' ? dot++ : dot;
		buf[i] == '#' ? sharp++ : sharp;
		i++;
	}
	if (dot != 12 || sharp != 4 || line != 4)
		return (0);
	if (buf[20] == '\n')
		line++;
	return (line);
}

static int	check_tetri(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (!(i + 1 % 5) && i != 0)
			if (buf[i] != '\n')
				return (0);
		if (buf[i] == '#')
		{
			(i + 1) < 20 && buf[i + 1] == '#' ? count++ : count;
			(i - 1) >= 0 && buf[i - 1] == '#' ? count++ : count;
			(i + 5) < 20 && buf[i + 5] == '#' ? count++ : count;
			(i - 5) >= 0 && buf[i - 5] == '#' ? count++ : count;
		}
		i++;
	}
	return (count == 6 || count == 8 ? count : 0);
}

int			input(char *av)
{
	int		fd;
	int		ret;
	char	buf[21];
	int		cnt_tetri;
	int		line;

	fd = open(av, O_RDONLY);
	cnt_tetri = 0;
	line = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if ((!check_block(buf)) || (!check_tetri(buf)) || (buf[0] == '\n'))
			return (0);
		else if (check_block(buf))
			line += check_block(buf);
		cnt_tetri++;
	}
	if ((line - cnt_tetri * 4 != cnt_tetri - 1) || cnt_tetri > 26)
		return (0);
	close(fd);
	return (ft_root(4 * cnt_tetri));
}
