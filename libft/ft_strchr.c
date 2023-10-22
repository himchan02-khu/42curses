/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:23:59 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 19:26:05 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, char c)
{
	char const	*ptr;
	int			index;

	ptr = str;
	index = 0;
	while (1)
	{
		if (ptr[index] == c)
			return ((char *)&ptr[index]);
		else if (ptr[index] == 0)
			return (NULL);
		index++;
	}
	return (NULL);
}
