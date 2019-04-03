/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:24 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/03 20:42:41 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*push(char *name)
{
    t_dir *new;

    if ((new = (t_dir *)malloc(sizeof(t_dir))) == NULL)
        return (NULL);
    new->name = name;
    new->next = NULL;
    return (new);
}

t_dir	*create_lst(t_dir **dir, char *name)
{
    t_dir *pos;
    t_dir *new_node;

    new_node = push(name);
    pos = *dir;
    while(pos && pos->next)
        pos = pos->next;
    if (pos)
        pos->next = new_node;
    else
        *dir = new_node;
    return (new_node);
}

t_dir	*opt_r(t_dir **dir, char *name)
{
    t_dir *pos;
    t_dir *new_node;

    new_node = push(name);
    pos = *dir;
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
/* ********************** WTF ******************** */
void    display_lst_vitef(t_dir *dir)
{
    while (dir)
    {
        printf("%s\n", dir->name);
        dir = dir->next;
    }
    printf(YEL"============================\n"NRM);
}

/* ********************** WTF ******************** */
t_dir   *sort_list(t_dir *lst)
{
    char *tmp;
    t_dir *start;

    start = lst;
    while (lst->next)
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
    lst = start;
    return (start);
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
                create_lst(&dir, concat(dirname, ft_strdup(read->d_name)));
        }
        if (!is_hidden(read->d_name, data))
            create_lst(&file, ft_strdup(read->d_name));
    }
    if (dir)
        dir = sort_list(dir);
    file = sort_list(file);
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
