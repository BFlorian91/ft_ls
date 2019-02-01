/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:09:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/01 14:33:25 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main	(int ac, char **av)
{
	struct 	dirent *pDirent;
	DIR 	*pDir;

	if (ac == 1)
	{
		pDir = opendir(".");
		if (pDir == NULL)
		{
			ft_printf("Cannot open directory '%s'\n", av[1]);
			return 1;
		}

		while ((pDirent = readdir(pDir)))
			ft_printf("%s ", pDirent->d_name);
		closedir (pDir);
	}
	else
	{
		pDir = opendir(av[1]);

		if (pDir == NULL)
		{
			perror("ERROR");
			exit(1);
		}
		else
		{
			while ((pDirent = readdir(pDir)))
			{
				ft_printf("Le type est: %hhu\n", pDirent->d_type);
				ft_printf("Le nom est: %s ", pDirent->d_name);
			}
			ft_putchar('\n');
			/* HOW TO USE STAT */
			struct stat buf;

			if (stat((const char *)av[1], &buf) != 1)
				ft_printf("STAT --> : %ld\n", buf.st_mode);
		}
		closedir(pDir);
	}
	return 0;
}
