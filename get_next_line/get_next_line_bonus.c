/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:07:26 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/24 17:18:46 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

int	strlen_clean(char *arr, int len)
{
	int	index;

	if (len == -1)
	{
		index = 0;
		while (arr[index] != 0)
			index++;
		return (index);
	}
	else
	{
		index = 0;
		while (index < len)
		{
			arr[index] = 0;
			index++;
		}
		arr[index] = 0;
		return (0);
	}
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

t_lst	*ft_lstnew(int fd, t_lst **head)
{
	struct s_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
	{
		free(lst);
		return (NULL);
	}
	if ((*head))
	{
		lst->next = (*head);
		(*head)->before = lst;
		(*head) = lst;
	}
	else
		lst->next = NULL;
	lst->before = NULL;
	lst->file = fd;
	strlen_clean(lst->save_buf, (int)BUFFER_SIZE);
	return (lst);
}

char	*get_next_line(int fd)
{
	static struct s_lst	*head;
	struct s_lst		*ptr;

	ptr = head;
	if (head)
		while (ptr->next != NULL && ptr->file != fd)
			ptr = ptr->next;
	if (read(fd, 0, 0) == -1 || fd < 0 || (int)BUFFER_SIZE < 0)
	{
		if (!head)
			return (NULL);
		if (ptr->file == fd && (int)BUFFER_SIZE >= 0)
			strlen_clean(ptr->save_buf, (int)BUFFER_SIZE);
		return (NULL);
	}
	if (!head)
		head = ft_lstnew(fd, &head);
	else if (ptr->next == NULL && ptr->file != fd)
		head = ft_lstnew(fd, &head);
	if (!head)
		return (NULL);
	else if (head->file == fd)
		return (pass_buf(fd, &head));
	else
		return (pass_buf(fd, &ptr));
}

char	*pass_buf(int fd, t_lst **ptr)
{
	int				buf_sz;
	char			*buf;

	buf_sz = (int)BUFFER_SIZE + strlen_clean((*ptr)->save_buf, -1);
	buf = (char *)malloc(sizeof(char) * (buf_sz + 1));
	if (!buf)
		return (lst_pull(ptr), NULL);
	strlen_clean(buf, buf_sz);
	buf = ft_strncpy(buf, (*ptr)->save_buf, strlen_clean((*ptr)->save_buf, -1));
	strlen_clean((*ptr)->save_buf, (int)BUFFER_SIZE);
	buf = alloc_buf(fd, buf_sz, ptr, buf);
	if (!buf)
		return (lst_pull(ptr), NULL);
	if (!*buf)
		return (free(buf), NULL);
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
	printf("string : %s ||", get_next_line(3));
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
	fd = open("lines_around_10.txt", O_RDWR);
	printf("fd (alter) : %d\n", fd);
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %s ||", get_next_line(fd));
	printf("string : %p ||", get_next_line(fd));
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

	//system("leaks a.out");
			}

*/
