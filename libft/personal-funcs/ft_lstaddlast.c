/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:40:28 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 15:45:01 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **start, t_list *new)
{
	t_list *last;

	last = *start;
	while (last && last->next)
		last = last->next;
	if (last)
		last->next = new;
	else
		*start = new;
}
