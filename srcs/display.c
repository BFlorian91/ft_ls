/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:07:54 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 12:34:45 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static void		permissions(char *av)
{
    struct stat fileStat;
    if(stat(&av[1], &fileStat) < 0)

    printf("Information for %c\n",av[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%llu\n",fileStat.st_ino);

    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}
*/

void			*fck_malloc(int size)
{
	void	*ret;

	if (!(ret = malloc(size)))
		exit(1);
	return ret;
}

t_list			*fck_lstnew(void *content, int size)
{
	t_list *new;
	if (!(new = malloc(sizeof(t_list))))
		exit(1);
	new->content = content;
	new->content_size = size;
	new->next = NULL;
	return new;
}

char			*concat(char *s1, char *s2)
{
	char	*ret;
	char	*tmp;

	tmp = ft_strjoin(s1, "/");
	ret = ft_strjoin(tmp, s2);
	free(tmp);
	return (ret);
}

static t_dir	*add_dir(char *str, t_datas *datas)
{
	t_list		*new;
	t_dir		*dir;

	dir = fck_malloc(sizeof(t_dir));
	new = fck_lstnew(dir, sizeof(dir));
	dir->name = str;
	dir->files = NULL;
	stat(str, &dir->file_stat);
	ft_printf("%s\n", ((t_dir *)new->content)->name);
	ft_lstaddlast(&datas->dirs, new);

	return (dir);
}

static t_list	*add_file(char *str, t_dir *dir, t_datas *datas)
{
	t_list		*new;
	t_file		*file;

	file = fck_malloc(sizeof(t_file));
	new = fck_lstnew(file, sizeof(file));
	file->name = ft_strdup(str);
	if (dir)
	{
		stat(concat(dir->name, str), &(file->file_stat));
		ft_lstaddlast(&dir->files, new);
	}
	else
	{
		stat(str, &file->file_stat);
		ft_lstaddlast(&datas->files, new);
	}
	return (new);
}

static void	parse_dir(char *dir_name, char *flags, t_datas *datas)
{
	t_dirent	*name;
	DIR			*directory;
	t_dir		*dir;

	directory = NULL;
	dir = NULL;
	name = NULL;

	if ((directory = opendir(dir_name)) == NULL)
	{
		perror("ls: ");
		exit(0);
	}
	dir = add_dir(dir_name, datas);
	while ((name = readdir(directory)))
	{
		if (ft_strstr(flags, "R") && ft_strcmp(name->d_name, ".") && ft_strcmp(name->d_name, ".."))
		{
		if (name->d_type == 4)
			parse_dir(concat(dir_name, name->d_name), flags, datas);
		}
		add_file(name->d_name, dir, datas);
	}
	closedir(directory);
}

void			parse_files(int ac, char **av, t_datas *datas, int i)
{
	struct stat	file_stat;
	while (i < ac)
	{
		if (stat(av[i], &file_stat) < 0)
			perror("ls: ");
		else if (S_ISDIR(file_stat.st_mode))
		{
			parse_dir(av[i], datas->flags, datas);
		}
		else
		{
			add_file(av[i], NULL, datas);
		}
		i++;
	}
}
