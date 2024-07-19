/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:38:57 by hchoo             #+#    #+#             */
/*   Updated: 2024/01/24 08:01:00 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	int				value;
	struct s_stack	*next;
}	t_stack;

int	check_arg(int argc, char **argv, t_stack **stack_a);
int	ft_atoi(char const *str);
int	two_arg(char **argv);
int	three_arg(char **argv);

#endif
