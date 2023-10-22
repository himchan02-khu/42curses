/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:24:51 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/08 21:25:07 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*ps1 && *ps2 && n > 0)
	{
		if (*ps1 != *ps2)
			return (n);
		ps1++;
		ps2++;
		n--;
	}
	if (*ps2 == 0)
		return (0);
	else if (*ps2 != 0 && n != 0)
		return (n);
	else
		return (-1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*ptr_str;
	const char	*ptr_tf;
	int			wordlen;

	ptr_str = str;
	wordlen = 0;
	if ((*ptr_str == 0 && *to_find == 0) || (*to_find == 0 && len == 0))
		return ((char *)str);
	while (to_find[wordlen] != 0)
		wordlen++;
	if ((unsigned int)len < (unsigned int)wordlen)
		return (NULL);
	while (*ptr_str != 0 && len > 0)
	{
		ptr_tf = to_find;
		if (f_strncmp((char *)ptr_str, (char *)ptr_tf, len) == 0)
			return ((char *)ptr_str);
		ptr_str++;
		len--;
	}
	return (NULL);
}
