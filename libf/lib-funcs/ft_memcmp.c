/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:02:31 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 15:03:16 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*source_1;
	unsigned char	*source_2;

	i = 0;
	if (n == 0)
		return (0);
	source_1 = (unsigned char *)s1;
	source_2 = (unsigned char *)s2;
	if (*source_1 == *source_2 && !n)
		return (0);
	while (*source_1++ == *source_2++ && n-- && n)
		;
	return (*--source_1 - *--source_2);
}
