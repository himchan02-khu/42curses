/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:02:21 by hchoo             #+#    #+#             */
/*   Updated: 2024/07/28 23:03:18 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char const *str)
{
	int			index;
	int			sign;
	long long	save;

	index = 0;
	sign = 1;
	save = 0;
	if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		save = save * 10 + sign * (str[index] - 48);
		index++;
	}
	if (str[index] != 0 || save > 2147483647 || save < -2147483648 || !index)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (save);
}

t_stack *alloc_stack(int value, t_stack *back, t_stack *front)
{
	t_stack	*alloc;

	alloc = (t_stack *)malloc(sizeof(t_stack));
	alloc->value = value;
	if (front != NULL)
		alloc->next = front;
	else
		alloc->next = NULL;
	if (back != NULL)
		alloc->prev = back;
	else
		alloc->prev = NULL;
	return (alloc);
}


int	check_arg(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*alloc;
	int		index;

	index = 1;
	if (*stack_a == NULL)
		(*stack_a) = alloc_stack(ft_atoi(argv[index++]), 0, 0);
	ptr = *stack_a;
	while (index < argc)
	{
		alloc = (t_stack *)malloc(sizeof(t_stack));
		alloc->value = ft_atoi(argv[index]);
		ptr->next = alloc;
		ptr = ptr->next;
		index++;
	}
	return (0);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		return (ft_atoi(argv[1]));
	else if (argc == 3)
		return (two_arg(argv));
	else if (argc == 4)
		return (three_arg(argv));
	if (check_arg(argc, argv, &stack_a) == -1)
		return (write(2, "Error\n", 6));
	for(t_stack *ptr = stack_a; ptr != NULL; ptr = ptr->next)
	{
		printf("%d\n",ptr->value);
		//stack_a = stack_a->next;
	}
}

