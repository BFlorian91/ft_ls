/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:40:36 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 14:02:53 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned int	i;
	unsigned char	character;

	p = b;
	i = 0;
	character = (unsigned char)c;
	while (i < len)
	{
		p[i] = character;
		++i;
	}
	return (p);
}
