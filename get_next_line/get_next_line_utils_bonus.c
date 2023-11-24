/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/24 17:29:55 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	lst_pull(t_lst **ptr)
{
	t_lst	*tmp;
	t_lst	*before;

	if (!(*ptr) || !ptr)
		return ;
	before = (*ptr)->before;
	tmp = (*ptr)->next;
	if ((*ptr)->next)
		((*ptr)->next)->before = before;
	if (before)
		before->next = tmp;
	strlen_clean((*ptr)->save_buf, (int)BUFFER_SIZE);
	(*ptr)->next = NULL;
	(*ptr)->before = NULL;
	free((*ptr));
	if (tmp)
		(*ptr) = tmp;
	else
		(*ptr) = 0;
}

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

char	*reallocate(char *buf, int *buf_sz, int new_buf_sz)
{
	char	*new_buf;

	new_buf = malloc(sizeof(char) * (new_buf_sz + 1));
	if (new_buf)
	{
		strlen_clean(new_buf, new_buf_sz);
		if (*buf_sz < new_buf_sz)
			ft_strncpy(new_buf, buf, *buf_sz);
		else
			ft_strncpy(new_buf, buf, new_buf_sz);
		strlen_clean(buf, *buf_sz);
		*buf_sz = new_buf_sz;
	}
	else
	{
		*buf_sz = 0;
		free(new_buf);
		free(buf);
		return (NULL);
	}
	free(buf);
	return (new_buf);
}

char	*clean_cpy(char *buf, char *save_buf, int buf_sz, int index)
{
	ft_strncpy(save_buf, buf + index + 1, buf_sz - index - 1);
	strlen_clean(buf + index + 1, buf_sz - index - 1);
	buf = reallocate(buf, &buf_sz, strlen_clean(buf, -1));
	if (!buf)
		return (NULL);
	return (buf);
}

char	*alloc_buf(int fd, int buf_sz, t_lst **ptr, char *buf)
{
	int	index;
	int	len;

	index = 0;
	if (check_buf_newline(buf, &index, buf_sz) == 1)
		return (clean_cpy(buf, (*ptr)->save_buf, buf_sz, index));
	while (buf)
	{
		len = read(fd, buf + buf_sz - (int)BUFFER_SIZE, (int)BUFFER_SIZE);
		if (check_buf_newline(buf, &index, buf_sz - (int)BUFFER_SIZE + len))
			return (clean_cpy(buf, (*ptr)->save_buf, buf_sz, index));
		if (len < (int)BUFFER_SIZE)
			break ;
		buf = reallocate(buf, &buf_sz, (int)BUFFER_SIZE + buf_sz);
		if (!buf)
			return (lst_pull(ptr), NULL);
	}
	if (len < (int)BUFFER_SIZE)
		lst_pull(ptr);
	if (len < 0 || (index == 0 && *buf == 0))
		return (buf);
	else if (len >= 0 && len < (int)BUFFER_SIZE)
		buf = reallocate(buf, &buf_sz, strlen_clean(buf, -1));
	return (buf);
}
