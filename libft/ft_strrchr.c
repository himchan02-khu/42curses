/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:24:11 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 15:32:21 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, char c)
{
	char	*ptr;
	int		index;
	char	*last_find;

	ptr = str;
	index = 0;
	last_find = 0;
	while (1)
	{
		if (ptr[index] == c)
			last_find = &ptr[index];
		if (ptr[index] == 0)
			break ;
		index++;
	}
	if (last_find == 0)
		return (NULL);
	else
		return (last_find);
}
