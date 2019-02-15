/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:59:31 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/06 19:06:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 1;
	while (str[i])
		i++;
	return (i);
}

int		write_test(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}


int		main(int ac, char **av)
{
	write_test(av[1]);
}
