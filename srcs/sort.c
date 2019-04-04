/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:49:32 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/04 11:14:04 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void   sorted_lst_swap(t_dir *lst, t_dir *start)
{
    char    *tmp;

    start = lst;
    while(lst->next)
    {
        if (ft_strcmp(lst->name, lst->next->name) > 0)
        {
            tmp = lst->name;
            lst->name = lst->next->name;
            lst->next->name = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
}


static void   unsorted_lst_swap(t_dir *lst, t_dir *start)
{
    char    *tmp;

    start = lst;
    while(lst->next)
    {
        if (ft_strcmp(lst->name, lst->next->name) < 0)
        {
            tmp = lst->name;
            lst->name = lst->next->name;
            lst->next->name = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
}

t_dir   *sort_list(t_dir *lst, bool sort)
{
    t_dir *start;

    start = lst;
    if (sort == true)
        sorted_lst_swap(lst, start);
    else if (sort == false)
        unsorted_lst_swap(lst, start);
    lst = start;
    return (start);
}
