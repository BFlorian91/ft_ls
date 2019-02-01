/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:45:26 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/21 14:25:26 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen((char *)s) - 1;
	while (is_space(s[start]))
		++start;
	while (is_space(s[end]) && end >= 0)
		--end;
	if (!s[start])
		start = 0;
	if (!(str = (char *)malloc((end - start) + 2)))
		return (NULL);
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
