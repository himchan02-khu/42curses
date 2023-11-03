/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/03 16:56:58 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*reallocate(char *buf, int *buf_sz, int new_buf_sz)
{
	char	*new_buf;

	new_buf = malloc(sizeof(char) * (new_buf_sz));
	if (new_buf)
	{
		ft_strncpy(new_buf, buf, *buf_sz);
		str_clean(buf, *buf_sz - 1);
		*buf_sz = new_buf_sz;
	}
	else
	{
		*buf_sz = 0;
		free(buf);
		return (NULL);
	}
	free(buf);
	buf = NULL;
	return (new_buf);
}

char	*read_file(int fd)
{
	char	*buf;
	static char	save_buf[BUFFER_SIZE + 1];
	int		buf_sz;
	int		index;
	int		len;

	buf_sz = (int)BUFFER_SIZE + ft_strlen(save_buf);
	buf = (char *)malloc(sizeof(char) * (buf_sz + 1));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
	index = 0;
	buf = ft_strncpy(buf, save_buf, ft_strlen(save_buf));
	str_clean(save_buf, (int)BUFFER_SIZE);
	if (check_buf_newline(buf, &index, buf_sz) == 1)
	{
		ft_strncpy(save_buf, buf + index + 1, buf_sz - index - 1);
		str_clean(buf + index + 1, buf_sz - index - 1);
		return (buf);
	}
	while (buf)
	{
		len = read(fd, buf + buf_sz - (int)BUFFER_SIZE, (int)BUFFER_SIZE);
		if (check_buf_newline(buf, &index, buf_sz - (int)BUFFER_SIZE + len) == 1)
		{
			ft_strncpy(save_buf, buf + index + 1, buf_sz - index - 1);
			str_clean(buf + index + 1, buf_sz - index - 1);
			return (buf);
		}
		if (len <= 0)
			break ;
		buf = reallocate(buf, &buf_sz, (int)BUFFER_SIZE + buf_sz);
	}
	if (len < 0 || (index == 0 && *buf == 0))
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
