/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:29:21 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/01 20:59:07 by alcaroff         ###   ########.fr       */
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

int		parsing(int ac, char **av);
int		check_opt(char *opt);
int		check_type(t_dirent *pDirent, DIR *pDir, int ac, char **av);

int		parse_flags(int ac, char **av, t_datas *datas);
int		parse_files(int ac, char **av, t_datas *datas, int i);




#endif