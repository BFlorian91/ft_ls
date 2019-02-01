/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:25:25 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 12:38:53 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n;

	n = ft_strlen((char *)needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_memcmp(haystack++, needle, n))
			return ((char *)--haystack);
	}
	return (0);
}
