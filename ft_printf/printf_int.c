/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:03:46 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 03:14:06 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int val)
{
	int		sign;
	int		len;
	char	rev_a[11];

	sign = (val < 0) * -1 + (val >= 0) * 1;
	len = 0;
	if (sign < 0)
		if (write(1, "-", 1) == -1)
			return (-1);
	while (val > 0 || val < 0)
	{
		rev_a[10 - len] = (val % 10) * sign + '0';
		val = val / 10;
		len++;
	}
	if (len == 0)
		return (write(1, "0", 1));
	if (write(1, rev_a + 11 - len, len) == -1)
		return (-1);
	else
		return (len + (sign < 0));
}

int	print_unsigned(int val)
{
	unsigned int	max;
	int				len;
	char			rev_a[10];

	max = -1;
	len = 0;
	if (val < 0)
		max = max + val + 1;
	if (max == (unsigned) -1)
		max = val;
	if (max == 0)
		return (write(1, "0", 1));
	while (max > 0)
	{
		rev_a[9 - len] = (max % 10) + '0';
		max = max / 10;
		len++;
	}
	return (write(1, rev_a + 10 - len, len));
}

int	print_16(unsigned int val, int sign)
{
	char		*tr;
	char		rev_l[10];
	int			len;

	tr = "0123456789ABCDEF";
	len = 0;
	if (val == 0)
		return (write(1, "0", 1));
	while (val)
	{
		rev_l[9 - len] = tr[val % 16];
		if (rev_l[9 - len] <= 'F' && rev_l[9 - len] >= 'A' && sign == 1)
			rev_l[9 - len] += 32;
		val /= 16;
		len++;
	}
	return (write(1, rev_l + 10 - len, len));
}
