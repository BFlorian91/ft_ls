/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:58:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/10 20:06:54 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*concat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((new = malloc(ft_strlen(s1) + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = '/';
	while (s2[j])
	{
		new[i] = s2[j++];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void        lst_insert(t_dir **lst, t_dir *node, t_data *data)
{
    t_dir   *current;
    t_dir   *tmp;

    current = *lst;
    if (!current)
        *lst = node;
    else if (ft_strstr(data->flags, "r") ? current->date < node->date 
            : current->date > node->date)
    {
        *lst = node;
        node->next = current;
    }
    else
    {
        while (current->next && current->next->date < node->date)
            current = current->next;
        tmp = current->next;
        current->next = node;
        node->next = tmp;
    }
}

void       sort(t_dir **lst, t_data *data)
{
    t_dir   *new_lst;
    t_dir   *current;
    t_dir   *tmp;

    new_lst = NULL;
    if (!lst)
        return ;
    current = *lst;
    while (current)
    {
        tmp = current->next;
        current->next = NULL;
        lst_insert(&new_lst, current, data);
        current = tmp;
    }
    *lst = new_lst;
}

