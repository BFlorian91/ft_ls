/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:24 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/10 20:08:50 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_dir           *push_back(t_dir **dir, char *name, unsigned int date)
{
    t_dir *pos;
    t_dir *new_node;

    if ((new_node = (t_dir *)malloc(sizeof(t_dir))) == NULL)
        return (NULL);
    new_node->name = name;
    new_node->date = date;
    new_node->next = NULL;
    pos = *dir;
    while(pos && pos->next)
        pos = pos->next;
    if (pos)
        pos->next = new_node;
    else
        *dir = new_node;
    return (new_node);
}

int		parse(char *dirname, int ac, t_data *data)
{
    t_dirent	        *read;
    DIR			*p_dir;
    t_dir		*file;
    t_dir		*dir;
    struct stat	        file_stat;

    file = NULL;
    dir = NULL;
    if ((p_dir = opendir(dirname)) == NULL)
    {
        perror("ls: ");
        return (-1);
    }
    while ((read = readdir(p_dir)))
    {
        stat(read->d_name, &file_stat);
        if ((read->d_type == 4) && ((opt_a(read->d_name, data))))
        {
            if (ft_strstr(data->flags, "R") 
                    && ft_strcmp(read->d_name, ".") && ft_strcmp(read->d_name, ".."))
            {
                push_back(&dir, concat(dirname, ft_strdup(read->d_name)), file_stat.st_mtime);
                /*printf(RED"--> %s: %ld secondes or %s\n"NRM, dir->name, file_stat.st_mtime, ctime(&file_stat.st_mtime));*/
            }
        }
        if (opt_a(read->d_name, data))
        {
            push_back(&file, ft_strdup(read->d_name)
                    , file_stat.st_mtime);
            /*printf(RED"--> %s: %ld secondes or %s\n"NRM, file->name, file_stat.st_mtime, ctime(&file_stat.st_mtime));*/
        }
    }

    /////////////////// SORT ////////////////////

    if (ft_strstr(data->flags, "t"))
    {
        if (!ft_strstr(data->flags, "r"))
        {
            if (dir)
                opt_test(&dir, data);
            if (file)
                opt_test(&file, data);
        }
        else
        {
            if (dir)
                opt_tr(&dir, data);
            if (file)
                opt_tr(&file, data);
        }
    }
    else
    {
        if (dir && ft_strstr(data->flags, "r"))
            dir = sort_list(dir, false);

        if (ft_strstr(data->flags, "r"))
            file = sort_list(file, false);
        else if (!ft_strstr(data->flags, "r"))
            file = sort_list(file, true);
    }
    
    //////////////////////////////////////////

    ////////////// DISPLAY ///////////////////
    if (ft_strstr(data->flags, "l"))
    {
        if (file)
            opt_l(file);
        if (dir)
            opt_l(dir);
    }
    else
        display_list(data, dirname, ac, file);

    //////////////////////////////////////////

    closedir(p_dir);
    ft_printf("\n");
    opt_r_upper(data, dir, ac);
    return (1);
}

int		road_to_parse(int ac, char **av, t_data *data, int i)
{
    struct stat	file_stat;

    if (ac == 1 || (ac == 2 && ft_strstr(data->flags, "R"))
            || (ac == 2 && ft_strstr(data->flags, "a"))
            || (ac == 2 && ft_strstr(data->flags, "r"))
            || (ac == 2 && ft_strstr(data->flags, "t"))
            || (ac == 2 && ft_strstr(data->flags, "l")))
        parse(".", ac, data);
    else
    {
        while (i < ac)
        {
            if ((stat(av[i], &file_stat)) < 0)
                perror(av[i]);
            else
                parse(av[i], ac, data);
            i++;
        }
    }
    return (0);
}
