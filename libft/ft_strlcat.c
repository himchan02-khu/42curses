/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:07:45 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:20:59 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	size_dest;
	size_t	size_src;
	size_t	tmp;

	size_dest = 0;
	size_src = 0;
	tmp = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[size_src] != '\0')
		size_src++;
	if (size < size_dest)
		return (size_src + size);
	else
	{
		while (tmp + 1 < size - size_dest && src[tmp] != '\0')
		{
			dest[size_dest + tmp] = src[tmp];
			tmp++;
		}
	}
	dest[size_dest + tmp] = '\0';
	return (size_dest + size_src);
}
