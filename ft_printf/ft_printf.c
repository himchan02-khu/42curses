/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:54:00 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/29 20:08:40 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	var_type(const char *arr)
{
	arr++;
	if (*arr == 'c')
		return (1);
	else if (*arr == 's')
		return (2);
	else if (*arr == 'p')
		return (3);
	else if (*arr == 'd')
		return (4);
	else if (*arr == 'i')
		return (5);
	else if (*arr == 'u')
		return (6);
	else if (*arr == 'x')
		return (7);
	else if (*arr == 'X')
		return (8);
	else if (*arr == '%')
		return (9);
	else
		return (0);
}

int	ft_printf(const char *arr, ...)
{
	char	*copy;
	int	size;
	int	arr_size;

	size = 0;
	arr_size = 0;
	while (arr[size])
		size++;
	copy = (char *)malloc(sizeof(char) * (size + 1));
	while (*arr)
	{
		copy[arr_size] = arr[arr_size];
		if (*arr == '%')


