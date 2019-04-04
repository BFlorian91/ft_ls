/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:33:41 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/11/21 14:24:52 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbr_nolomit(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		nbr_nolomit(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	nbr_nolomit(n, fd);
}
