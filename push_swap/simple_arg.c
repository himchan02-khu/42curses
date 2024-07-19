/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:02:31 by hchoo             #+#    #+#             */
/*   Updated: 2024/01/24 08:04:06 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	two_arg(char **argv)
{
	int	index;
	int	first;

	index = 1;
	first = ft_atoi(argv[index++]);
	if (ft_atoi(argv[index]) < first)
		write(1, "sa\n", 3);
	return (0);
}

int	three_arg(char **argv)
{
	int	first;
	int	second;
	int	third;

	first = ft_atoi(argv[1]);
	second = ft_atoi(argv[2]);
	third = ft_atoi(argv[3]);
	if (first < second && first < third && second > third)
		write(1, "sa\nra\n", 6);
	else if (first < second && first > third)
		write(1, "rra\n", 4);
	else if (first > second && first < third)
		write(1, "sa\n", 3);
	else if (first > second && first > third && second < third)
		write(1, "ra\n", 3);
	else if (first > second && first > third && second > third)
		write (1, "sa\nrra\n", 7);
	return (0);
}
