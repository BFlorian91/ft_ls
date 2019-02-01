/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:04:17 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/21 14:28:56 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_str(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		++count;
	}
	if (n == 0)
		++count;
	while (n > 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*result;
	int		is_neg;
	long	nb;

	nb = (long)n;
	size = size_str(nb);
	is_neg = 0;
	if (nb < 0)
	{
		is_neg = 1;
		nb *= -1;
	}
	if (!(result = ft_strnew(size)))
		return (NULL);
	result[size] = '\0';
	while (size)
	{
		--size;
		result[size] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_neg == 1)
		result[0] = '-';
	return (result);
}
