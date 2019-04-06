/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:33:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/06 14:54:22 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

u_int   sort_date(u_int a, u_int b)
{
    return (a < b);
}

int     opt_r_upper(t_data *data, t_dir *dir, int ac)
{
    if (ft_strstr(data->flags, "R"))
    {
        while (dir)
        {
            parse(dir->name, ac, data);
            dir = dir->next;
        }
    }
    return (0);
}

void    wild(t_dir *lst)
{
    while (lst)
    {
        CDEBUG(lst->name);
        lst = lst->next;
    }
}

t_dir   *opt_t(t_dir *lst)
{
    char    *tmp_name;
    u_int    tmp_date;
    t_dir   *start;

    start = lst;
    while(lst && lst->next)
    {
        if (sort_date(lst->date, lst->next->date) > 0)
        {
            tmp_name = lst->name;
            tmp_date = lst->date;
            lst->name = lst->next->name;
            lst->date = lst->next->date;
            lst->next->name = tmp_name;
            lst->next->date = tmp_date;
            lst = start;
        }
        lst = lst->next;
    }
    lst = start;
    wild(lst);
    return (lst);
}

t_dir   *opt_tr(t_dir *lst)
{
    char    *tmp_name;
    u_int    tmp_date;
    t_dir   *start;

    start = lst;
    while(lst && lst->next)
    {
        if (sort_date(lst->next->date, lst->date) > 0)
        {
            tmp_name = lst->name;
            tmp_date = lst->date;
            lst->name = lst->next->name;
            lst->date = lst->next->date;
            lst->next->name = tmp_name;
            lst->next->date = tmp_date;
            lst = start;
        }
        lst = lst->next;
    }
    lst = start;
    wild(lst);
    return (lst);
}

int	opt_a(char *dirname, t_data *data)
{
    if (!(ft_strstr(data->flags, "a")))
        if (!(ft_strncmp(dirname, ".", 1)))
            return (0);
    return (1);
}
