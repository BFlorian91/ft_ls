/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:33:31 by florian           #+#    #+#             */
/*   Updated: 2019/01/10 14:29:12 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define MAX_FD 4864
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

int			get_next_line(const int fd, char **line);

#endif
