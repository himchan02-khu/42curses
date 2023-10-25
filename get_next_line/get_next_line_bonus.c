/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/15 23:28:14 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

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
	int	count;

	count = 0;
	while (count < n && src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = src[count];
	return (dest);
}

t_lst	*ft_lstnew(int fd, const t_lst *head)
{
	struct s_lst	*lst;
	struct s_lst	*ptr;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
	{
		free(lst);
		return (NULL);
	}
	if (head)
	{
		ptr = (t_lst *)head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		printf("last list adr : %p\n",ptr);
		ptr->next = lst;
	}
	lst->next = NULL;
	lst->file = fd;
	return (lst);
}

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


#include <fcntl.h>
int main()
{
	int	fd;
	char *buf = (char *) malloc (sizeof(char) * 1024);
	char *receive;

	fd = open("43", O_RDWR);
	printf("%p\n", buf);
	free(buf);
	printf("%p\n", buf);

	receive = get_next_line(fd);
	//printf("%zd", read(fd, buf, 1024));
//	printf("main print buf : %s\n\n", get_next_line(fd));
//	printf("%s\n\n", get_next_line(fd));
//	fd = open("empty", O_RDWR);
	printf("main print buf : %s\n\n", receive);
	receive = get_next_line(fd);
	fd = open("42", O_RDWR);
	printf("%s\n\n", receive);
	receive = get_next_line(fd);
	//fd = open("43", O_RDWR);
	printf("main print buf : %s\n\n", receive);
	fd = open("42", O_RDWR);
	receive = get_next_line(fd);
	printf("%s\n\n", receive);
	printf("%d\n", BUFFER_SIZE);
	printf("%lu", sizeof(t_lst));
	system("leaks a.out");
			}

