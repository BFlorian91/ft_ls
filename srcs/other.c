/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:58:16 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/02 14:58:53 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*concat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((new = malloc(ft_strlen(s1) + ft_strlen(s2) + 2)) == NULL)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = '/';
	while (s2[j])
	{
		new[i] = s2[j++];
		i++;
	}
	new[i] = '\0';
	return (new);
}

