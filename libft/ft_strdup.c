/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:47:45 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 15:32:14 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*dup;
	const char	*ptr_src;
	int			size;

	size = 0;
	ptr_src = src;
	while (ptr_src[size] != '\0')
		size++;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (!dup)
		return (NULL);
	dup[size] = 0;
	while (size--)
		dup[size] = ptr_src[size];
	return (dup);
}
