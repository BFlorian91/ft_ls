/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:25:47 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 15:18:43 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	i = 0;
	source = (unsigned char *)s;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return (source + i);
		++i;
	}
	return (NULL);
}
