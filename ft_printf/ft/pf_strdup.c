/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 22:14:18 by alcaroff          #+#    #+#             */
/*   Updated: 2019/02/01 20:53:54 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*pf_strdup(const char *s)
{
	char	*dup;

	if (s == NULL)
		return (NULL);
	if ((dup = (char *)malloc((pf_strlen(s) + 1))) == NULL)
		return (NULL);
	pf_strcpy(dup, s);
	return (dup);
}
