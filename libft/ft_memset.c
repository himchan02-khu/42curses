/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:06:20 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 15:32:05 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int val, size_t len)
{
	size_t			index;
	unsigned char	*convert;

	convert = (unsigned char *)ptr;
	index = 0;
	while (index < len)
		convert[index++] = (unsigned char)val;
	return (convert);
}
