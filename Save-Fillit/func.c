/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:15:25 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/13 20:38:48 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tri	*clean_lst(t_tri *lst)
{
	while (lst != NULL)
	{
		free(lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_display(t_tri *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i = 0;
		ft_putchar('\n');
		ft_putchar(lst->c);
		ft_putchar('\n');
		while (i < 4)
		{
			printf("%d [x:%d, y:%d]\n", i, lst->pos[i].x, lst->pos[i].y); // <- DELETE
			i++;
		}
		lst = lst->next;
	}
}


