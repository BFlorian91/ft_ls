/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:33:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/06 18:56:16 by flbeaumo         ###   ########.fr       */
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

////// DEBUG ///////////////

void    wild(t_dir *lst)
{
    while (lst)
    {
        CDEBUG(lst->name);
        lst = lst->next;
    }
}

////////////////////////////

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
    return (lst);
}

int	opt_a(char *dirname, t_data *data)
{
    if (!(ft_strstr(data->flags, "a")))
        if (!(ft_strncmp(dirname, ".", 1)))
            return (0);
    return (1);
}

void    opt_l(t_dir *lst)
{
    struct stat file_stat;


    while (lst)
    {
        stat(lst->name, &file_stat);
        ft_printf("Name: %s\n", lst->name);
        ft_printf("---------------------------\n");
        ft_printf("File Size: \t\t%lld bytes\n", file_stat.st_size);
        ft_printf("File inode: \t\t%lld\n" ,file_stat.st_ino);
        ft_printf("Number of Links: \t%d\n" ,file_stat.st_nlink);
        ft_printf("Symbolic link: \t\t%lld\n", (S_ISLNK(file_stat.st_mode)) ? "Yes" : "No" );

        ft_printf("File Permissions: \t");
        ft_printf( (S_ISDIR(file_stat.st_mode)) ? "d" : "-");
        ft_printf( (file_stat.st_mode & S_IRUSR) ? "r" : "-");
        ft_printf( (file_stat.st_mode & S_IWUSR) ? "w" : "-");
        ft_printf( (file_stat.st_mode & S_IXUSR) ? "x" : "-");
        ft_printf( (file_stat.st_mode & S_IRGRP) ? "r" : "-");
        ft_printf( (file_stat.st_mode & S_IWGRP) ? "w" : "-");
        ft_printf( (file_stat.st_mode & S_IXGRP) ? "x" : "-");
        ft_printf( (file_stat.st_mode & S_IROTH) ? "r" : "-");
        ft_printf( (file_stat.st_mode & S_IWOTH) ? "w" : "-");
        ft_printf( (file_stat.st_mode & S_IXOTH) ? "x" : "-");
        ft_printf("\n\n");
        lst = lst->next;
    }
}
