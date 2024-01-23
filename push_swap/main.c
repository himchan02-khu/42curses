#include "push_swap.h"

int	ft_atoi(char const *str)
{
	int	index;
	int	sign;
	int	save;

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
	if (str[index] != 0)
		return (-1);
	return (save);
}

int	check_arg(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*alloc;
	int	index;

	index = 1;
	if (*stack_a == NULL)
	{
		(*stack_a) = (t_stack *)malloc(sizeof(t_stack));
		(*stack_a)->value = ft_atoi(argv[index++]);
		if ((*stack_a)->value == -1)
			return (-1);
	}
	ptr = *stack_a;
	while (index < argc)
	{
		alloc = (t_stack *)malloc(sizeof(t_stack));
		alloc->value = ft_atoi(argv[argc]);
		if (alloc->value == -1)
			return (-1);
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
		return 0;
	if (check_arg(argc, argv, &stack_a) == -1)
		return (write(2, "Error\n", 6));
	for(;stack_a != NULL; stack_a = stack_a->next)
	{
		printf("%d\n",stack_a->value);
		stack_a = stack_a->next;
	}
}

