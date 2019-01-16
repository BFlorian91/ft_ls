/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:43:53 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/16 19:30:48 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>

/*
typedef struct	s_map
{
	int		size;
	char	**tab;
}				t_map;
*/

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_tri
{
	char			c;
	t_point			pos[4];
	struct s_tri	*next;
}				t_tri;

t_tri			*parse(char *av);
t_tri			*clean_lst(t_tri *lst);
int				input(char *av);
char			**create_map(int size);
void			print_map(char **map, int size);
void			ft_display(t_tri *lst);
void			place_t(t_tri *lst, char **map, int i, int j);
int				solving(t_tri *tetriminos, char **map, int size);
char			**resize_map(char **map, int size);

#endif
