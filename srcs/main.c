/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:33:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/03 22:22:50 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


/*
 * Segfault sur ./ft_ls -R /
*/

int		main(int ac, char **av)
{
	main_display(ac, av);
	return (0);
}
