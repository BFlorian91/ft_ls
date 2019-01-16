/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:49:11 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/14 18:33:03 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

	fd = open(av, O_RDONLY);
	cnt_tetri = 0;
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (!check_block(buf))
			return (0);
		if (!check_tetri(buf))
			return (0);
		cnt_tetri++;
	}
	close(fd);
	return (ft_sqrt(4 * cnt_tetri));
}
