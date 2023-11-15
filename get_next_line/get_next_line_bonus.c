/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 07:27:39 by hchoo            ###   ########.fr       */
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

t_lst	*ft_lstnew(int fd, const t_lst *head)
{
	struct s_lst	*lst;
	struct s_lst	*ptr;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	if (head)
	{
		ptr = (t_lst *)head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		lst->before = ptr;
		ptr->next = lst;
	}
	else
		lst->before = NULL;
	lst->next = NULL;
	lst->file = fd;
	str_clean(lst->save_buf, (int)BUFFER_SIZE);
	return (lst);
}

char	*get_next_line(int fd)
{
	static struct s_lst	*head;
	struct s_lst		*ptr;
	char				*buf;
	int					buf_sz;

	if (read(fd, 0, 0) == -1 || fd < 0 || (int)BUFFER_SIZE < 0)
	{
		if (head == 0)
			return (NULL);
		ptr = head;
		while (ptr->next != NULL && ptr->file != fd)
			ptr = ptr->next;
		if (ptr->file == fd)
			str_clean(ptr->save_buf, (int)BUFFER_SIZE);
		return (NULL);
	}
	if (!head)
		head = ft_lstnew(fd, head);
	if (!head)
		return (NULL);
	ptr = head;
	while (ptr->next != NULL && ptr->file != fd)
		ptr = ptr->next;
	if (ptr->next == NULL && ptr->file != fd)
		ptr->next = ft_lstnew(fd, head);
	if (ptr != head && ptr->file != fd)
		ptr = ptr->next;
	buf_sz = (int)BUFFER_SIZE + ft_strlen(ptr->save_buf);
	buf = (char *)malloc(sizeof(char) * (buf_sz + 1));
	if (!buf)
		return (NULL);
	str_clean(buf, buf_sz);
	buf = ft_strncpy(buf, ptr->save_buf, ft_strlen(ptr->save_buf));
	str_clean(ptr->save_buf, (int)BUFFER_SIZE);
	if (ptr == head)
		buf = alloc_buf(fd, buf_sz, &head, buf);
	else
		buf = alloc_buf(fd, buf_sz, &ptr, buf);
	return (buf);
}
/*

#include <fcntl.h>
int main()
{
	int	fd;

	fd = open("one_line_no_nl.txt", O_RDWR);
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
	printf("string : %s", get_next_line(fd));
	printf("%d\n", BUFFER_SIZE);
	fd = open("empty", O_RDWR);
	printf("fd (alter) : %d\n", fd);
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	fd = open("1", O_RDWR);
	printf("fd (alter) : %d\n", fd);
	printf("string : %s ||", get_next_line(fd));
	fd = open("mul_nl", O_RDWR);
	printf("fd (alter) : %d\n", fd);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(4));
	printf("string : %s ||", get_next_line(4));
	fd = open("empty", O_RDWR);
	printf("fd (alter) : %d\n", fd);
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(6));
	printf("string : %s ||", get_next_line(6));
	printf("string : %s ||", get_next_line(5));
	printf("string : %s ||", get_next_line(4));
	printf("string : %s ||", get_next_line(4));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	fd = open("43", O_RDWR);
	printf("fd (alter) : %d\n", fd);
//	fd = 100;
	printf("main print buf : %s", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));

	system("leaks a.out");
			}

*/
