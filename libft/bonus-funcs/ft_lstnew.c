/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:32:44 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/21 16:58:58 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	if (!(new_lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		new_lst->content_size = content_size;
		new_lst->content = malloc(content_size);
		ft_memcpy(new_lst->content, content, content_size);
	}
	new_lst->next = NULL;
	return (new_lst);
}
