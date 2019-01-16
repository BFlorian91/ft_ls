/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:43:07 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/16 19:46:29 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tri	*lst;
	t_tri	*start;
	char	**map;
	int		size;
	int		i;

	i = 4;
	lst = NULL;
	start = lst;
	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (0);
	}
	if (ac == 2)
	{
		if ((size = input(av[1])))
		{
			printf("Taille de la map (ORIGIN): %d\n\n", size);
			map = create_map(size);
			lst = parse(av[1]);
			while (lst)
			{
				if (!solving(lst, map, size))
				{
					ft_putendl("1 - Solving -> FAIL\n");
					ft_putendl("2 - Resize map\n");
					if (!(map = resize_map(map, size++)))
						return (-1);
					printf("Taille de la map (RESIZE): %d\n\n", size);
					printf("Piece implacable:\t%c\n", lst->c);
				}
				else
					ft_putendl("3 - Solving -> OK\n");
				lst = lst->next;
			}
			print_map(map, size);
		}
	}
	return (0);
}
