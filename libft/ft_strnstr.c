/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:08:05 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 12:41:00 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	n = ft_strlen((char *)needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && len >= n)
	{
		if (!ft_memcmp(haystack++, needle, n))
			return ((char *)--haystack);
		--len;
	}
	return (0);
}
