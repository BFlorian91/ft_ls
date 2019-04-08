/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:47:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/07 11:17:43 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    display_list(t_data *data, char *dirname, int nb_folders, t_dir *file)
{
    struct stat file_stat;

    if (nb_folders > 2 || (nb_folders == 2 
                && !ft_strstr(data->flags, "R"))
            || (nb_folders == 2 && (ft_strstr(data->flags, "R")
                    || ft_strstr(data->flags, "a"))
                && (ft_strcmp(dirname, ".") > 0)))
        ft_printf(BLU"%s:\n"NRM, dirname);
    while (file)
    {
        stat(file->name, &file_stat);
        if (S_ISDIR(file_stat.st_mode))
            ft_printf(BLU"%s\n", file->name);
        else if (file_stat.st_mode & S_IXUSR)
            ft_printf(RED"%s\n", file->name);
        else    
            ft_printf(NRM"%s\n", file->name);
        file = file->next;
    }
}
