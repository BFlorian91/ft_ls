/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:07:54 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/02 16:41:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	display_basic(t_datas datas)
{
	while (datas.dirs)
	{
		ft_printf("dir -> %s\n", (char *)(datas.dirs->content));
		datas.dirs = datas.dirs->next;
	}
	while (datas.files)
	{
		ft_printf("file -> %s\n", (char *)(datas.files->content));
		datas.files = datas.files->next;
	}
}
*/


static void	recursif(t_datas *datas)
{
	t_dirent	*name;
	char 		**str;
	int			i;
	int 		j;

	i = 0;
	j = 0;
	if ((str = (char **)malloc(sizeof(t_datas))) == NULL)
		return ;
	while (datas->dirs)
	{
		str[i][j] = (char *)datas->dirs->content;
		i++;
		datas->dirs->content = datas->dirs->next;
	}
	i = 0;
	if ((datas->directory = opendir(str[i])) == NULL)
	{
		perror("ls: ");
		exit(0);
	}
	while ((name = readdir(datas->directory)))
	{
		if (ft_strcmp(name->d_name, ".") && ft_strcmp(name->d_name, ".."))
		{
			ft_printf("%s\n", name->d_name);
			//recursif(name->d_name);
		}
	}

}

void		display_basic(int ac, char **av, t_datas *datas) 
{
	if (parse_flags(ac, av, datas))
	{
	//	recursif(datas);	
	}
}

