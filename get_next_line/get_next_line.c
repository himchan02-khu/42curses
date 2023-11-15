/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 02:09:03 by hchoo            ###   ########.fr       */
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
	while (arr[size] != 0)
		size++;
	return (size);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	save_buf[BUFFER_SIZE + 1];
	char		*buf;
	int			buf_sz;

	if (read(fd, 0, 0) == -1 || fd == -1)
		return (NULL);
	buf_sz = (int)BUFFER_SIZE + ft_strlen(save_buf);
	buf = (char *)malloc(sizeof(char) * (buf_sz + 1));
	if (!buf)
	{
		free(buf);
		return (NULL);
	}
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
	char *buf = (char *) malloc (sizeof(char) * 1024);

	fd = open("43", O_RDWR);
	printf("%p\n", buf);
	free(buf);
	printf("%p\n", buf);

	//printf("%zd", read(fd, buf, 1024));
//	printf("main print buf : %s\n\n", get_next_line(fd));
//	printf("%s\n\n", get_next_line(fd));
//	fd = open("empty", O_RDWR);
//	printf("main print buf : %s\n\n", get_next_line(fd));
//	printf("%s\n\n", get_next_line(fd));
//	fd = open("42", O_RDWR);
//	printf("main print buf : %s\n\n", get_next_line(fd));
//	printf("%s\n\n", get_next_line(fd));
	fd = open("42_n", O_RDWR);
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
//	printf("%lu", sizeof(t_lst));
			//printf("after enter buf[index] : %s || \n", &buf[index + 1]);
			//printf("after enter buf[index] : %d || \n", buf[index + 1]);
			//printf("buf : %s || \n", buf);
			//printf("buflen : %d || \n", ft_strlen(buf));
			//printf("address buf : %p || \n", buf);
			//printf("address buf[index + 1] : %p || \n", buf + index + 1);
			//printf("index : %d ||\n", index + 1);
			//printf("save_buf in check_buf_newline : %s ||\n", save_buf);
//	system("leaks a.out");
			}
*/
