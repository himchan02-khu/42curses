/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:04:57 by hyunjunl          #+#    #+#             */
/*   Updated: 2023/08/08 10:51:57 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "bsq.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		++len;
	return (len);
}

int	ft_str_is_printable(char *str)
{
	int	ret;

	ret = 1;
	while (*str)
	{
		if (!(32 <= *str && *str <= 126))
			ret = 0;
		++str;
	}
	return (ret);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (*src)
	{
		if (len + 1 < size)
			*dest++ = *src;
		++src;
		++len;
	}
	if (size > 0)
		*dest = '\0';
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);
	ft_strlcpy(dup, src, len + 1);
	return (dup);
}

int	ft_count(char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
		if (*str++ == c)
			++cnt;
	return (cnt);
}
