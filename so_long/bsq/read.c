/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:19:17 by hyunjunl          #+#    #+#             */
/*   Updated: 2023/08/09 17:37:03 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

char	**ft_split(char *str, char sep)
{
	char	**tokens;
	int		cnt;
	int		index;
	int		row;

	cnt = ft_count(str, sep);
	tokens = malloc(sizeof(char *) * (cnt + 1));
	if (tokens == 0)
		return (0);
	row = 0;
	while (row < cnt)
	{
		index = 0;
		while (str[index] != sep)
			++index;
		str[index] = '\0';
		tokens[row] = ft_strdup(str);
		if (tokens[row++] == 0)
			break ;
		str += index + 1;
	}
	tokens[row] = 0;
	return (tokens);
}

char	*ft_memcpy(char *dest, char *src, unsigned int size)
{
	char	*ret;

	ret = dest;
	while (size > 0)
	{
		*dest++ = *src++;
		--size;
	}
	return (ret);
}

char	*reallocate(char *buf, int *buf_sz, int new_buf_sz)
{
	char	*new_buf;

	new_buf = malloc(sizeof(char) * new_buf_sz);
	if (new_buf)
	{
		ft_memcpy(new_buf, buf, *buf_sz);
		*buf_sz = new_buf_sz;
	}
	else
		*buf_sz = 0;
	free(buf);
	return (new_buf);
}

char	*read_file(int fd)
{
	char	*buf;
	int		buf_sz;
	int		total_len;
	int		len;

	buf_sz = 2;
	buf = malloc(sizeof(char) * buf_sz);
	total_len = 0;
	while (buf)
	{
		len = read(fd, buf + total_len, buf_sz / 2);
		if (len <= 0)
			break ;
		total_len += len;
		if (total_len >= buf_sz / 2)
			buf = reallocate(buf, &buf_sz, 2 * buf_sz);
	}
	if (buf == 0 || contain(buf, total_len, '\0'))
	{
		free(buf);
		return (0);
	}
	buf[total_len] = '\0';
	return (buf);
}
