/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:54:00 by hchoo             #+#    #+#             */
/*   Updated: 2023/11/16 03:34:17 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	var_type(const char arr, va_list *args)
{
	if (arr == 'c')
		return (print_char(va_arg(*args, int)));
	else if (arr == 's')
		return (print_str(va_arg(*args, char *)));
	else if (arr == 'p')
		return (print_address(va_arg(*args, void *)));
	else if (arr == 'd')
		return (print_int(va_arg(*args, int)));
	else if (arr == 'i')
		return (print_int(va_arg(*args, int)));
	else if (arr == 'u')
		return (print_unsigned(va_arg(*args, int)));
	else if (arr == 'x')
		return (print_16(va_arg(*args, unsigned int), 1));
	else if (arr == 'X')
		return (print_16(va_arg(*args, unsigned int), 0));
	else if (arr == '%')
		return (write(1, &arr, 1));
	else
		return (0);
}

int	ft_printf(const char *arr, ...)
{
	int		len;
	va_list	args;
	int		result;

	len = 0;
	va_start(args, arr);
	while (*arr != 0)
	{
		result = 0;
		if (*arr == '%' && *(arr + 1) != 0)
			result = var_type(*++arr, &args);
		else if (*arr == '%' && *(arr + 1) == 0)
			return (len);
		else if (write(1, arr, 1) == -1)
			return (-1);
		if (result == -1)
			return (-1);
		else if (result > 0)
			len += result - 1;
		len += 1 - (result == -2);
		arr++;
	}
	va_end(args);
	return (len);
}
/*

int main()
{
	int len = 0;
	static char *asdf = "asdf";
	printf("%d : \n\n", ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	printf("%d : ", printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 "));
	printf("%d : \n\n", ft_printf(" %s", ""));
}
*/
