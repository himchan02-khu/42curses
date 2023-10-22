/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/22 06:56:50 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
//	buf = (char *)malloc(sizeof(char) * bufsize);
	buf = read_file(fd);
	return (buf);
//	len = read(fd, &buf[index], 1);
	/*
	while (len != 0 && len != -1 && index < bufsize)
	{
		if (buf[index] != '\n')
			len = read(fd, &buf[++index], 1);
		else
			return (buf);
	}
	if (len == -1 || (len == 0 && *buf == 0))
	{
		free(buf);
		return (NULL);
	}
	else
		return (buf);
		*/
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
	printf("main print buf : %s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	fd = open("42", O_RDWR);
	printf("main print buf : %s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%d\n", BUFFER_SIZE);
	printf("%lu", sizeof(t_lst));
	system("leaks a.out");
			}
*/