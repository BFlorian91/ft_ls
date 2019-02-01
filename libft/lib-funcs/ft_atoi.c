/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:41:56 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/22 14:02:56 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v'
			|| c == '\r');
}

int			ft_atoi(const char *str)
{
	long long int	value;
	long long int	neg;
	int				i;

	value = 0;
	neg = 1;
	i = 0;
	while (is_space(str[i]))
		++i;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	while (ft_isdigit(str[i]) && str[i])
		value = value * 10 + str[i++] - 48;
	return (value * neg);
}
