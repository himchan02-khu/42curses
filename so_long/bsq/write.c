/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjunl <hyunjunl@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 02:47:13 by hyunjunl          #+#    #+#             */
/*   Updated: 2023/08/08 11:09:33 by hyunjunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "bsq.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(void)
{
	write(2, "map error\n", 10);
}

void	print_lines(char **lines)
{
	while (*lines)
	{
		ft_putstr(*lines++);
		ft_putstr("\n");
	}
}
