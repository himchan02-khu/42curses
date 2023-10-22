/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/15 23:28:14 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*buf;
	int	len;
	int	index;

	len = 1;
	index = 0;
	if (fd == -1)
		return (NULL);
	buf = read_file(fd);
	return (buf);
}
