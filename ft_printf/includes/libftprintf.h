/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:25:58 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 21:00:18 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>

typedef struct	s_spe
{
	char				spe;
	char				conv[3];
	int					zero;
	int					hash;
	int					space;
	int					plus;
	int					minus;
	int					error;
	long long int		width;
	long long int		precision;
	char				*s;
	struct s_spe		*next;
}				t_spe;

int				ft_printf(const char *format, ...);
int				parser(char *fmt, va_list *ap, t_spe **start);
int				parse_str(t_spe *start, va_list ap);
int				check_exceptions(t_spe *start);
int				print_specifier(t_spe *e);

int				lst_del(t_spe *start);
t_spe			*init_elem(t_spe **start, t_spe *elem);

int				is_specifier(int c);
int				is_flag(int c);
int				is_conv(int c);

char			*pf_itoa_base(long long n, int base);
char			*pf_itoa_base_un(unsigned long long n, int base);
char			*pf_getwstr(wchar_t *str, t_spe *e);
char			*pf_getwchar(wchar_t c, t_spe *e);
char			*pf_getchar(char c);

int				pf_atoi(const char *s);
void			pf_bzero(void *s, size_t n);
int				pf_isalpha(int c);
int				pf_isdigit(int c);
int				pf_strcmp(const char *s1, const char *s2);
char			*pf_strcpy(char *dest, const char *src);
char			*pf_strdup(const char *s);
char			*pf_strndup(const char *s, int n);
size_t			pf_strlen(const char *s);
char			*pf_strtolower(char *str);
int				pf_strisspace(const char *str);
int				pf_putstr(const char *s);
int				pf_putchar(int c);

#endif
