/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:33:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/05 19:06:35 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_dir   *opt_t(t_dir *lst)
{
    char    *tmp;
    t_dir   *start;

    start = lst;
    while(lst && lst->next)
    {
        if (sort_int(lst->date, lst->next->date) > 0)
        {
            tmp = lst->name;
            lst->name = lst->next->name;
            lst->next->name = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
    lst = start;
    return (lst);
}

int	opt_a(char *dirname, t_data *data)
{
    if (!(ft_strstr(data->flags, "a")))
        if (!(ft_strncmp(dirname, ".", 1)))
            return (1);
    return (0);
}
