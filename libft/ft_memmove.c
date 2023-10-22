/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:07:05 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 17:41:01 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *ptr, const void *src, size_t len)
{
	char		*ptr_tmp;
	const char	*tmp;

	if (ptr == 0 && src == 0)
		return (NULL);
	ptr_tmp = ptr;
	tmp = src;
	if (ptr_tmp < tmp)
		while (len--)
			*ptr_tmp++ = *tmp++;
	else
	{
		ptr_tmp += len;
		tmp += len;
		while (len--)
			*--ptr_tmp = *--tmp;
	}
	return (ptr);
}
