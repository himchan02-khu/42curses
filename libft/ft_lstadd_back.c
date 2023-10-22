/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 02:26:40 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/09 02:44:54 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*ptr;

	ptr = (*lst);
	if (!(*lst))
		(*lst) = newlst;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newlst;
	}
}
