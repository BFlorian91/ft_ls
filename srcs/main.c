/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:18:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/02/06 22:30:31 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_data	data;
	int		ret;

	ret = 1;
	ret = parse_flags(ac, av, &data);
	parse_files(ac, av, &data, ret);
}
