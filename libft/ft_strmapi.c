/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:33:49 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 16:56:03 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f) (unsigned int, char))
{
	unsigned int	index;
	unsigned int	size;
	char			*alloc;

	index = 0;
	size = 0;
	while (str[size] != 0)
		size++;
	alloc = (char *)malloc(sizeof(char) * (size + 1));
	if (!(alloc))
		return (NULL);
	while (index < size)
	{
		alloc[index] = f(index, str[index]);
		index++;
	}
	alloc[index] = 0;
	return (alloc);
}
