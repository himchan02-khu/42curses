/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/03 13:26:54 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

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

char	*buf_alloc(char *buf, int index, int buf_sz, t_lst *ptr)
{
	int	len;

	len = 1;
	while (buf && len != 0)
	{
		len = read(ptr->file, buf + buf_sz - (int)BUFFER_SIZE, (int)BUFFER_SIZE);
		if (check_buf_newline(buf, ptr->save_buf, &index, buf_sz) == 1)
		{
		//	if (len == 0) //endoffile = before -> next = now->next
		//		lst_pull(ptr);
			return (buf);
		}
		if (len <= 0 && len < BUFFER_SIZE)
			break ;
		buf = reallocate(buf, &buf_sz, (int)BUFFER_SIZE + buf_sz);
	}
//	if (len >= 0 && len < BUFFER_SIZE)
	//	lst_pull(ptr);
	if (len < 0 || (index == 0 && *buf == 0))
	{
		lst_pull(ptr);
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*read_file(int fd)
{
	char	*buf;
	int		buf_sz;
	int		index;
	static struct s_lst	*head;
	struct s_lst		*ptr;

	if (!head)
		head = ft_lstnew(fd, NULL);
	ptr = head;
	while (ptr->next != NULL && ptr->file != fd)
		ptr = ptr->next;
	if (ptr->next == NULL)
		ptr->next = ft_lstnew(fd, head);
	buf = malloc(sizeof(char) * ((int)BUFFER_SIZE + ft_strlen(ptr->save_buf)));
	if (!buf)
	{
		lst_pull(ptr);
		free(buf);
		return (NULL);
	}
	buf_sz = (int)BUFFER_SIZE + ft_strlen(ptr->save_buf);
	str_clean(buf, buf_sz);
	index = 0;
	buf = ft_strncpy(buf, ptr->save_buf, ft_strlen(ptr->save_buf));
	//buf_sz = (int)BUFFER_SIZE + ft_strlen(ptr->save_buf);
	if (check_buf_newline(buf, ptr->save_buf, &index, buf_sz) == 1)
		return (buf);
	buf = buf_alloc(buf, index, buf_sz, ptr);
//	printf("save_buf in fd %d : %s\n", ptr->file, ptr->save_buf);
	if (*buf == 0)
		lst_pull(ptr);
	return (buf);
}
