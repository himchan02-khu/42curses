/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:06:39 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 16:58:19 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *ptr, const void *src, size_t len)
{
	char		*ptr_tmp;
	const char	*src_tmp;
	size_t		size;

	size = 0;
	if (ptr == 0 && src == 0)
		return (NULL);
	ptr_tmp = ptr;
	src_tmp = src;
	while (size++ < len)
		*ptr_tmp++ = *src_tmp++;
	return (ptr);
}
