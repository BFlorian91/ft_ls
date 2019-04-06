/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:29:21 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/06 18:56:26 by flbeaumo         ###   ########.fr       */
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


/* RAINBOW DEBUG */
# define DEBUG(x) 	printf(RED"D"BLU"E"YEL"B"GRN"U"MAG"G:"CYN" %d\n"NRM, x)

# define CDEBUG(y) 	printf(RED"D"BLU"E"YEL"B"GRN"U"MAG"G:"CYN YEL" %s\n"NRM, y)

# define ERROR(z) 	z ? printf(RED"D"BLU"E"YEL"B"GRN"U"MAG"G:"GRN"[ GREAT ] \
"YEL"VALUE: "GRN"OK\n"NRM) : \
			printf(RED"D"BLU"E"YEL"B"GRN"U"MAG"G:"CYN RED"[ ERROR ] \
"YEL"VALUE: "RED"NULL\n"NRM)

# define fname		printf(YEL"["RED" DEBUG "YEL"]"CYN" ->"MAG" %s \n"NRM, read->d_name)

/* ************* */

typedef int bool;
typedef unsigned int u_int;

#define true 1
#define false 0

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/libftprintf.h"

typedef struct	dirent	t_dirent;

typedef struct			s_dir
{
	char 			*name;
	unsigned int		date;
	struct s_dir	 	*next;
}				t_dir;

typedef struct			s_data
{
	char			*all_files;
	char			flags[255];
}				t_data;


int		parse_flags(int ac, char **av, t_data *data);
int		road_to_parse(int ac, char **av, t_data *data, int i);
void		display_list(t_data *data, char *dirname, int nb_folders, t_dir *file);
char		*concat(char *s1, char *s2);
int             opt_r_upper(t_data *data, t_dir *dir, int ac);
int		opt_a(char *dirname, t_data *data);
int		parse(char *dirname, int ac, t_data *data);
t_dir		*sort_list(t_dir *lst, bool sort);
t_dir 		*opt_t(t_dir *lst);
t_dir 		*opt_tr(t_dir *lst);
void    	opt_l(t_dir *lst);

#endif
