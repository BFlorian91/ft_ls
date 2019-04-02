/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:47:37 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/02 15:43:47 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_list(char *dirname, int nb_folders, t_dir *file)
{
        if (nb_folders > 2)
            ft_printf(BLU"%s:\n"NRM, dirname);
	while (file)
	{
		printf("%s\n", file->name);
		file = file->next;
	}
}
