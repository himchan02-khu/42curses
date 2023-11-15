/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:12:53 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/15 21:47:34 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

void	lst_pull(t_lst **ptr)
{
	t_lst *before;

	if ((*ptr)->before == NULL)
	{
		close((*ptr)->file);
		before = (*ptr);
		if ((*ptr)->next != NULL)
			(*ptr) = (*ptr)->next;
		else
			(*ptr) = 0;
		str_clean(before->save_buf, (int)BUFFER_SIZE);
		before->next = NULL;
		before->before = NULL;
		free(before);
		return ;
	}
	else
		before = (*ptr)->before;
	if ((*ptr)->next != NULL)
	{
		before->next = (*ptr)->next;
		((*ptr)->next)->before = before;
	}
	else
		before->next = NULL;
	close((*ptr)->file);
	str_clean((*ptr)->save_buf, (int)BUFFER_SIZE);
	(*ptr)->next = NULL;
	(*ptr)->before = NULL;
	free((*ptr));
	//(*ptr) = 0;
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

	new_buf = malloc(sizeof(char) * (new_buf_sz));
	if (new_buf)
	{
		str_clean(new_buf, new_buf_sz - 1);
		ft_strncpy(new_buf, buf, *buf_sz);
		str_clean(buf, *buf_sz - 1);
		*buf_sz = new_buf_sz;
	}
	else
	{
		*buf_sz = 0;
		free(new_buf);
		return (NULL);
	}
	free(buf);
	return (new_buf);
}

char	*clean_cpy(char *buf, char *save_buf, int buf_sz, int index)
{
	ft_strncpy(save_buf, buf + index + 1, buf_sz - index - 1);
	str_clean(buf + index + 1, buf_sz - index - 1);
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
			return (NULL);
	}
	if (len < 0 || (index == 0 && *buf == 0) || !buf)
	{
		lst_pull(ptr);
		if (buf)
			free(buf);
		return (NULL);
	}
	else if (len >= 0 && len < (int)BUFFER_SIZE)
		lst_pull(ptr);
	return (buf);
}
