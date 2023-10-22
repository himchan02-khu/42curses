/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:31:50 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 15:32:48 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	char	*alloc;
	int		size_prefix;
	int		size_suffix;

	size_prefix = 0;
	size_suffix = 0;
	while (prefix[size_prefix] != 0)
		size_prefix++;
	while (suffix[size_suffix] != 0)
		size_suffix++;
	alloc = (char *)malloc(sizeof(char) * (size_suffix + size_prefix + 1));
	if (!alloc)
		return (NULL);
	alloc[size_suffix + size_prefix] = 0;
	while (size_suffix-- > 0)
		alloc[size_suffix + size_prefix] = suffix[size_suffix];
	while (size_prefix-- > 0)
		alloc[size_prefix] = prefix[size_prefix];
	return (alloc);
}
