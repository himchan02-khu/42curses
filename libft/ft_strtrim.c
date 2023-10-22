/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:54:50 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 23:23:21 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_in_base(char c, char const *base)
{
	int	index;

	index = 0;
	while (base[index] != '\0')
	{
		if (c == base[index])
			return (1);
		index++;
	}
	return (0);
}

static void	check_word(char const *str, char const *word, int len, int *tf)
{
	int	index;

	index = 0;
	tf[0] = 0;
	tf[1] = 0;
	while (index < len)
	{
		if (c_in_base(str[index], word) == 1)
			tf[0]++;
		else
			break ;
		index++;
	}
	index = 0;
	while (index < len)
	{
		if (c_in_base(str[len - index - 1], word) == 1)
			tf[1]++;
		else
			break ;
		index++;
	}
	return ;
}

char	*ft_strtrim(char const *str, char const *word)
{
	int		length;
	int		tf[2];
	int		index;
	char	*alloc;

	length = 0;
	index = 0;
	while (str[length])
		length++;
	check_word(str, word, length, tf);
	if (tf[0] + tf[1] < length)
		length = length - tf[0] - tf[1];
	else
		length = 0;
	alloc = (char *)malloc(sizeof(char) * (length + 1));
	if (!alloc)
		return (NULL);
	if (length + tf[1] + tf[0] >= 0)
		str += tf[0];
	while (length-- > 0 && *str != 0)
		alloc[index++] = *str++;
	alloc[index] = 0;
	return (alloc);
}
