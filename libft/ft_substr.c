/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:05:27 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 22:31:39 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	index;
	size_t	str_len;
	char	*alloc;

	index = 0;
	str_len = 0;
	while (str[str_len] != 0)
		str_len++;
	if (str_len <= start || *str == 0)
		alloc = (char *)malloc(sizeof(char) * (1));
	else if (str_len < len + start)
		alloc = (char *)malloc(sizeof(char) * (str_len - start + 1));
	else
		alloc = (char *)malloc(sizeof(char) * (len + 1));
	if (!alloc)
		return (NULL);
	while (index < len && start + index < str_len)
	{
		alloc[index] = str[index + start];
		index++;
	}
	alloc[index] = 0;
	return (alloc);
}
