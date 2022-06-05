/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:21:09 by youssef           #+#    #+#             */
/*   Updated: 2021/11/21 17:57:26 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cursor_1;
	t_list	*cursor_2;

	if (!f || !del)
		return (NULL);
	cursor_1 = lst;
	cursor_2 = NULL;
	while (cursor_1)
	{
		cursor_2 = ft_lstnew(f(cursor_1->content));
		if (!cursor_2)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, cursor_2);
		cursor_1 = cursor_1->next;
	}
	return (new_lst);
}
