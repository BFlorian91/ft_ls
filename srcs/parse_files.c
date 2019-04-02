/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:24 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/02 15:45:19 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*make_node(char *name)
{
    t_dir *new;

    if ((new = (t_dir *)malloc(sizeof(t_dir))) == NULL)
        return (NULL);
    new->name = name;
    new->next = NULL;
    return (new);
}

t_dir	*add_push_back(t_dir **dir, char *name)
{
    t_dir *pos;
    t_dir *new_node;

    new_node = make_node(name);
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


static int		parse_dir(char *dirname, int ac, t_data *data)
{
    t_dirent	*read;
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
            if (ft_strstr(data->flags, "R")
                    && ft_strcmp(read->d_name, ".") && ft_strcmp(read->d_name, ".."))
                add_push_back(&dir, concat(dirname, ft_strdup(read->d_name)));
        if (!is_hidden(read->d_name, data))
            add_push_back(&file, ft_strdup(read->d_name));
    }
    display_list(dirname, ac, file);
    closedir(p_dir);
    ft_printf("\n");
    if (ft_strstr(data->flags, "R"))
    {
        while (dir)
        {
            parse_dir(dir->name, ac, data);
            dir = dir->next;
        }
    }
    return (1);
}

int		parse_files(int ac, char **av, t_data *data, int i)
{
    struct stat	file_stat;

    if (ac == 1 || (ac == 2 && ft_strstr(data->flags, "R")))
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
