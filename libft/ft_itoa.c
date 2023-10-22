/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:36:34 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/09 00:52:16 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	reverse(char *rev_a, int input, int sign)
{
	int	len;

	len = 0;
	while (input > 0 || input < 0)
	{
		rev_a[len] = (input % 10) * sign + '0';
		input = input / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int input)
{
	char	rev_a[12];
	char	*alloc;
	char	*tmp_alloc;
	int		len;
	int		sign;

	sign = (input < 0) * -1 + (input >= 0) * 1;
	len = reverse(rev_a, input, sign);
	rev_a[len] = 0;
	alloc = (char *)malloc(sizeof(char) * (len + (sign < 0) + 1 + (len == 0)));
	if (!alloc)
		return (NULL);
	tmp_alloc = alloc;
	if (sign < 0)
		*alloc++ = '-';
	if (len == 0)
		*alloc++ = '0';
	else
		while (len--)
			*alloc++ = rev_a[len];
	*alloc = 0;
	return (tmp_alloc);
}
