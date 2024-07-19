/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:04:57 by hyunjunl          #+#    #+#             */
/*   Updated: 2023/08/09 17:36:51 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "bsq.h"

int	contain(char *str, int len, char c)
{
	int	i;

	i = 0;
	while (i < len)
		if (str[i++] == c)
			return (1);
	return (0);
}

int	count_lines(char **lines)
{
	int	cnt;

	cnt = 0;
	while (*lines++)
		++cnt;
	return (cnt);
}

int	*alloc_int_arr(int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (arr == 0)
		return (0);
	i = 0;
	while (i < size)
		arr[i++] = 0;
	return (arr);
}

int	min(int a, int b, int c)
{
	int	minv;

	minv = a;
	if (minv > b)
		minv = b;
	if (minv > c)
		minv = c;
	return (minv);
}

void	free_strs(char **strs)
{
	int	i;

	if (strs == 0)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
