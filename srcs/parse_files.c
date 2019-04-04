/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:24 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/04 11:10:14 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_dir	*push_back(t_dir **dir, char *name)
{
    t_dir *pos;
    t_dir *new_node;

    if ((new_node = (t_dir *)malloc(sizeof(t_dir))) == NULL)
        return (NULL);
    new_node->name = name;
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

static int		is_hidden(char *dirname, t_data *data)
{
    if (!(ft_strstr(data->flags, "a")))
        if (!ft_strncmp(dirname, ".", 1))
            return (1);
    return (0);
}



int		parse_dir(char *dirname, int ac, t_data *data)
{
    t_dirent	        *read;
    DIR			*p_dir;
    t_dir		*file;
    t_dir		*dir;

    file = NULL;
    dir = NULL;
    if ((p_dir = opendir(dirname)) == NULL)
    {
        perror("ls: ");
        return (-1);
    }
    while ((read = readdir(p_dir)))
    {
        if ((read->d_type == 4) && (!(is_hidden(read->d_name, data))))
        {
            if (ft_strstr(data->flags, "R") 
                    && ft_strcmp(read->d_name, ".") && ft_strcmp(read->d_name, ".."))
                push_back(&dir, concat(dirname, ft_strdup(read->d_name)));
        }
        if (!is_hidden(read->d_name, data))
            push_back(&file, ft_strdup(read->d_name));
    }
    if (dir && ft_strstr(data->flags, "r"))
        dir = sort_list(dir, true);
    !ft_strstr(data->flags, "r") ? (file = sort_list(file, true)) : (file = sort_list(file, false));
    display_list(data, dirname, ac, file);
    closedir(p_dir);
    ft_printf("\n");
    opt_r_upper(data, dir, ac);
    return (1);
}

int		parse_files(int ac, char **av, t_data *data, int i)
{
    struct stat	file_stat;

    if (ac == 1 || (ac == 2 && ft_strstr(data->flags, "R"))
            ||(ac == 2 && ft_strstr(data->flags, "a")))
        parse_dir(".", ac, data);
    while (i < ac)
    {
        if ((stat(av[i], &file_stat)) < 0)
            perror(av[i]);
        else
            parse_dir(av[i], ac, data);
        i++;
    }
    return (0);
}
