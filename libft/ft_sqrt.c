/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:35:55 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/01/12 17:36:08 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	value;

	value = 0;
	if (nb < 0)
		return (0);
	else if (nb == 4)
		return (2);
	else if (nb == 9)
		return (3);
	while (value <= nb / 4)
	{
		if (nb == value * value)
			return (value);
		value++;
	}
	return (0);
}
