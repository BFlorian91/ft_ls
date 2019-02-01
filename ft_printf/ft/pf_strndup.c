/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:03:19 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 20:54:12 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (n < 0)
		n = pf_strlen(s);
	if ((dup = malloc(n + 1)) == NULL)
		return (NULL);
	while (s && s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
