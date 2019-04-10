/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:24:00 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/10 19:43:00 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putint(int *tab, int size)
{
    int     i;

    i = -1;
    while (++i < size)
    {
        ft_putnbr(tab[i]);
        if (i != (size - 1))
            ft_putstr(", ");
    }
    ft_putchar('\n');
}
