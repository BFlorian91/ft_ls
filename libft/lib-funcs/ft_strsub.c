/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:01:50 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/12/12 18:01:01 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len)
	{
		str[i] = s[start];
		++start;
		++i;
		--len;
	}
	str[i] = '\0';
	return (str);
}
