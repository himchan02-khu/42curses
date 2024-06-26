/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:17:22 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/25 22:13:52 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero(void *ptr, size_t len)
{
	char	*save_ptr;

	save_ptr = (char *)ptr;
	while (len--)
		*save_ptr++ = 0;
}

void	*ft_calloc(size_t len, size_t size)
{
	void	*alloc;

	if (size == 0 || len == 0)
		len = 0;
	else if (size > ~(size_t)0 / len)
		return (NULL);
	alloc = (void *)malloc(size * len);
	if (!alloc)
		return (NULL);
	ft_zero(alloc, len * size);
	return (alloc);
}
