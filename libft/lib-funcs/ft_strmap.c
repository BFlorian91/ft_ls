/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:07:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 12:45:56 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;
	int		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char*)s);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(s[i]);
		++i;
	}
	str[i] = '\0';
	return (str);
}
