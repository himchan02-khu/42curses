/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 02:48:58 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/09 03:02:20 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!(*lst))
		return ;
	else
	{
		while ((*lst) != NULL)
		{
			ptr = (*lst);
			del((*lst)->content);
			(*lst) = (*lst)->next;
			free(ptr);
		}
	}
}
