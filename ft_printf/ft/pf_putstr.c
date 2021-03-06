/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 21:45:47 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 20:57:16 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pf_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		pf_putchar(s[i]);
		i++;
	}
	return (i);
}
