/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:33:07 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/09 05:30:28 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	save_cal(char const *str, int index, int sign)
{
	int	save;

	save = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = save * 10 + sign * (str[index] - 48);
		index++;
	}
	return (save);
}

static int	check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(char const *str)
{
	int	index;
	int	sign;
	int	save;

	index = 0;
	sign = 1;
	while ((check_space(str[index]) == 1))
		index++;
	if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	else if (str[index] == '+')
		index++;
	save = save_cal(str, index, sign);
	return (save);
}
