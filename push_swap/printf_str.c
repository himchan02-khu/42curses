/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:13:37 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 03:34:16 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int val)
{
	char	c;

	c = val;
	return (write(1, &c, 1));
}

int	print_str(char *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (write(1, "(null)", 6));
	while (*(ptr + len) != '\0')
		len++;
	if (len == 0)
		return (-2);
	return (write(1, ptr, len));
}

int	print_address(void *addr)
{
	char				*tr;
	char				rev_l[64];
	unsigned long long	iaddr;
	int					len;

	tr = "0123456789abcdef";
	iaddr = (unsigned long long)addr;
	len = 0;
	if (iaddr == 0)
		return (write(1, "0x0", 3));
	while (iaddr)
	{
		rev_l[63 - len] = tr[iaddr % 16];
		iaddr /= 16;
		len++;
	}
	rev_l[63 - len++] = 'x';
	rev_l[63 - len++] = '0';
	return (write(1, rev_l + 64 - len, len));
}
