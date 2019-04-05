/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:18:35 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/04/05 09:43:49 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	int	ret;
	t_data  data;

	ret = 1;
	ret = parse_flags(ac, av, &data);
	road_to_parse(ac, av, &data, ret);
        return (0);
}
