/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 14:44:37 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/27 19:01:52 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_specifier(int c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'o' ||
			c == 'X' || c == 'x' || c == 'O' || c == 'p' ||
			c == 'c' || c == 's' || c == 'S' || c == 'C' ||
			c == 'U');
}

int		is_flag(int c)
{
	return (c == ' ' || c == '-' || c == '+' || c == '#' || c == '0');
}

int		is_conv(int c)
{
	return (c == 'l' || c == 'z' || c == 'h' || c == 'j');
}