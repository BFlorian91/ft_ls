/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bb_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:27:27 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/08 15:32:21 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int     bb_printf(const void *source)
{
    char *str;

    str = ((char *)source);
    ft_putstr(str);
    return (1);
}


int     main(int ac, char **av)
{
    (void)av;
    if (ac == 1)
    {
        bb_printf("Hello World\n");
        bb_printf(ac);
    }
    return (0);
}
