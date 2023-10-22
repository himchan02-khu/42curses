/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/21 21:24:12 by hchoo            ###   ########.fr       */
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

int	check_buf_newline(char *buf, char *save_buf, int *index, int buf_sz)
{
	while (*index < buf_sz && *(buf + *index) != 0)
	{
		if (buf[*index] == '\n')
		{
			ft_strncpy(save_buf, buf + *index + 1, ft_strlen(buf) - *index);
			buf[*index + 1] = 0;
			return (1);
		}
		else
			*index += 1;
	}
	return (0);
}

char	*reallocate(char *buf, int *buf_sz, int new_buf_sz)
{
	char	*new_buf;

	new_buf = malloc(sizeof(char) * (new_buf_sz));
	if (new_buf)
	{
		ft_strncpy(new_buf, buf, *buf_sz);
		//printf("new_buf_sz : %d\n", new_buf_sz);
		*buf_sz = new_buf_sz;
	}
	else
		*buf_sz = 0;
	free(buf);
	return (new_buf);
}

t_lst	*ft_lstnew(int fd)
{
	struct s_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
	{
		free(lst);
		return (NULL);
	}
	lst->next = NULL;
	lst->file = fd;
	return (lst);
}

char	*read_file(int fd)
{
	char	*buf;
	int		buf_sz;
	int		index;
	int		len;
	static struct s_lst	*head;
	struct s_lst		*ptr;

	if (!head)
		head = ft_lstnew(fd);
	ptr = head;
	while (ptr->next != NULL && ptr->file != fd)
		ptr = ptr->next;
	if (ptr->next == NULL && ptr->file != fd)
		ptr = ft_lstnew(fd);
	buf = malloc(sizeof(char) * ((int)BUFFER_SIZE + ft_strlen(ptr->save_buf)));
	index = 0;
	buf = ft_strncpy(buf, ptr->save_buf, ft_strlen(ptr->save_buf));
	buf_sz = (int)BUFFER_SIZE + ft_strlen(ptr->save_buf);
	if (check_buf_newline(buf, ptr->save_buf, &index, buf_sz) == 1)
		return (buf);
	while (buf)
	{
		len = read(fd, buf + buf_sz - (int)BUFFER_SIZE, (int)BUFFER_SIZE);
		if (check_buf_newline(buf, ptr->save_buf, &index, buf_sz) == 1)
			return (buf);
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
