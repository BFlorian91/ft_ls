/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:29:21 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 22:22:59 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"


/** DEBUG **/
# define DEBUG(x) printf(RED"D"BLU"E"YEL"B"GRN"U"MAG"G:"CYN" %d\n"NRM, x);

/***********/

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/libftprintf.h"

typedef struct dirent	t_dirent;

typedef struct	s_datas
{
	t_list		*dirs;
	t_list		*files;
	char		flags[255];
}				t_datas;

typedef struct	s_dir {
	t_list		*files;
	char		*name;
	struct stat file_stat;
}				t_dir;

typedef struct	s_file {
	char		*name;
	struct stat	file_stat;	
}				t_file;

int		parse_flags(int ac, char **av, t_datas *datas);
void	parse_files(int ac, char **av, t_datas *datas, int i);
int		main_display(int ac, char **av);

#endif

/*
datas
{
	dirs (lst)
	{
		1
		2
		3->content	(t_dir)
					name (srcs/)
					stat ..
					files (lst)
						1
						2
						3
						4->content (t_file)
									name
									stat
	}

	files (lst)
	{
		1
		2
		3->content (t_file)
					name
					stat
	}

	flags (str)
}
*/
