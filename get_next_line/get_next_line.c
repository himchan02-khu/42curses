/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 05:29:18 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buf_newline(char *buf, int *index, int buf_sz)
{
	while (*index < buf_sz && *(buf + *index) != 0)
	{
		if (buf[*index] == '\n')
			return (1);
		else
			*index += 1;
	}
	return (0);
}

void	str_clean(char *buf, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		buf[index] = 0;
		index++;
	}
	buf[index] = 0;
}

int	ft_strlen(char const *arr)
{
	int	size;

	size = 0;
	while (*(arr + size) != 0)
		size++;
	return (size);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	index;

	index = 0;
	while (index < n && *(src + index) != 0)
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = *(src + index);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	save_buf[BUFFER_SIZE + 1];
	char		*buf;
	int			buf_sz;

	if (read(fd, 0, 0) == -1 || fd == -1 || (int)BUFFER_SIZE < 0)
	{
		str_clean(save_buf, (int)BUFFER_SIZE);
		return (NULL);
	}
	buf_sz = (int)BUFFER_SIZE + ft_strlen(save_buf);
	buf = (char *)malloc(sizeof(char) * (buf_sz + 1));
	if (!buf)
		return (NULL);
	str_clean(buf, buf_sz);
	buf = ft_strncpy(buf, save_buf, ft_strlen(save_buf));
	str_clean(save_buf, (int)BUFFER_SIZE);
	buf = alloc_buf(fd, buf_sz, save_buf, buf);
	return (buf);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int	fd;

	fd = open("variable_nls.txt", O_RDWR);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s", get_next_line(fd));
	printf("%d\n", BUFFER_SIZE);
	fd = open("alter", O_RDWR);
	printf("fd (alter) : %d\n", fd);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s", get_next_line(fd));
	printf("%d\n", BUFFER_SIZE);
	fd = open("lines_around_10.txt", O_RDWR);
	printf("fd (alter) : %d\n", fd);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	fd = open("43", O_RDWR);
	printf("fd (alter) : %d\n", fd);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));

}

*/
