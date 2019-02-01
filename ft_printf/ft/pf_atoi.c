/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:56:53 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 20:55:44 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	pf_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

int			pf_atoi(const char *s)
{
	int		is_negative;
	int		nb;

	nb = 0;
	is_negative = 0;
	while (pf_isspace(*s))
		s++;
	if (!pf_strcmp("-2147483648", s))
		return (-2147483648);
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		is_negative = 1;
		s++;
	}
	while (pf_isdigit(*s))
	{
		nb = (nb * 10) + *s - '0';
		s++;
	}
	return (is_negative ? -nb : nb);
}
