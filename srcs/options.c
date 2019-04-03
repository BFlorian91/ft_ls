/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:33:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/02 18:05:00 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int                     opt_r_upper(t_data *data, t_dir *dir, int ac)
{
    if (ft_strstr(data->flags, "R"))
    {
        while (dir)
        {
            parse_dir(dir->name, ac, data);
            dir = dir->next;
        }
    }
    return (0);
}

