/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:07:32 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:20:33 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	index;
	size_t	size_src;

	index = 0;
	size_src = 0;
	while (src[size_src] != '\0')
		size_src++;
	if (size == 0)
		return (size_src);
	while (index < size - 1 && src[index] != '\0')
	{
		if (src[index] != '\0')
			dest[index] = src[index];
		else
			break ;
		index++;
	}
	dest[index] = '\0';
	return (size_src);
}
