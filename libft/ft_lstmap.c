/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchoo <hchoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 03:02:27 by hchoo             #+#    #+#             */
/*   Updated: 2023/10/11 15:21:50 by hchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*listnew(void *content, void (*del) (void *))
{
	struct s_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
	{
		del(content);
		return (NULL);
	}
	list->next = NULL;
	if (!content)
		list->content = NULL;
	else
		list->content = content;
	return (list);
}

static void	listadd_back(t_list **lst, t_list *newlst)
{
	t_list	*ptr;

	ptr = (*lst);
	if (!newlst)
		return ;
	if (!(*lst))
		(*lst) = newlst;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newlst;
	}
}

static void	listclear(t_list **lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**ptr;
	t_list	*new_lst;
	t_list	*result;

	if (!lst)
		return (NULL);
	else
	{
		ptr = &lst;
		result = NULL;
		while (lst != NULL)
		{
			new_lst = listnew(f(lst->content), del);
			if (!new_lst)
				free(new_lst);
			else
				listadd_back(&result, new_lst);
			lst = lst->next;
		}
		listclear(ptr, del);
		return (result);
	}
}
