/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:55:31 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 12:46:22 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	int		i;

	if (!(dst = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (s1[i] && n)
	{
		dst[i] = s1[i];
		++i;
		--n;
	}
	dst[i] = '\0';
	return (dst);
}
