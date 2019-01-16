/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:13:05 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/26 18:13:28 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		cw(const char *s, char c)
{
	int count;
	int	i;

	count = 0;
	i = 0;
	if (*s && s[i] != c)
	{
		count++;
		i++;
	}
	if (*s)
		i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			++count;
		++i;
	}
	return (count);
}

static int		ln(char const *s, int i, char c)
{
	int length;

	length = 0;
	while (*s && s[i] != c && s[i])
	{
		++length;
		++i;
	}
	return (length);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	k = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (cw(s, c) + 1))))
		return (NULL);
	while (s[k])
	{
		while (s[k] && s[k] == c)
			++k;
		if (s[k])
		{
			j = 0;
			if (!(str[i] = (char *)malloc(sizeof(char) * (ln(s, k, c) + 1))))
				return (NULL);
			while (s[k] && s[k] != c)
				str[i][j++] = s[k++];
			str[i++][j] = '\0';
		}
	}
	str[i] = NULL;
	return (str);
}
