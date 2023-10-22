/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:24:25 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 21:51:15 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t len)
{
	unsigned char	*ptr_arr;
	unsigned char	n;

	ptr_arr = (unsigned char *)arr;
	n = c;
	while (len--)
	{
		if (*ptr_arr == n % 256)
			return ((void *)ptr_arr);
		ptr_arr++;
	}
	return (NULL);
}
