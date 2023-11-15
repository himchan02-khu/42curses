/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 06:01:56 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*reallocate(char *buf, int *buf_sz, int new_buf_sz)
{
	char	*new_buf;

	new_buf = malloc(sizeof(char) * ((new_buf_sz) + 1));
	if (new_buf)
	{
		str_clean(new_buf, new_buf_sz);
		if (*buf_sz < new_buf_sz)
			ft_strncpy(new_buf, buf, *buf_sz);
		else
			ft_strncpy(new_buf, buf, new_buf_sz);
		str_clean(buf, *buf_sz);
		*buf_sz = new_buf_sz;
	}
	else
	{
		*buf_sz = 0;
		free(buf);
		return (NULL);
	}
	free(buf);
	return (new_buf);
}

char	*clean_cpy(char *buf, char *save_buf, int buf_sz, int index)
{
	ft_strncpy(save_buf, buf + index + 1, buf_sz - index - 1);
	str_clean(buf + index + 1, buf_sz - index - 1);
	buf = reallocate(buf, &buf_sz, ft_strlen(buf));
	return (buf);
}

char	*alloc_buf(int fd, int buf_sz, char *save_buf, char *buf)
{
	int	index;
	int	len;

	index = 0;
	if (check_buf_newline(buf, &index, buf_sz) == 1)
		return (clean_cpy(buf, save_buf, buf_sz, index));
	while (buf)
	{
		len = read(fd, buf + buf_sz - (int)BUFFER_SIZE, (int)BUFFER_SIZE);
		if (check_buf_newline(buf, &index, buf_sz - (int)BUFFER_SIZE + len))
			return (clean_cpy(buf, save_buf, buf_sz, index));
		if (len < (int)BUFFER_SIZE)
			break ;
		buf = reallocate(buf, &buf_sz, (int)BUFFER_SIZE + buf_sz);
		if (!buf)
			return (NULL);
	}
	if (len < 0 || (index == 0 && *buf == 0))
	{
		free(buf);
		return (NULL);
	}
	else if (len >= 0 && len < (int)BUFFER_SIZE)
		buf = reallocate(buf, &buf_sz, ft_strlen(buf));
	return (buf);
}
