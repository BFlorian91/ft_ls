/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:07:54 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/02 12:21:57 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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


