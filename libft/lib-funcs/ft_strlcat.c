/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:11:39 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/20 12:47:27 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t src_len;
	size_t dst_len;

	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	if (dst_len >= size)
		return (size + src_len);
	ft_strncat(dst, src, size - dst_len - 1);
	return (dst_len + src_len);
}
