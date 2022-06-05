/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:06:10 by youssef           #+#    #+#             */
/*   Updated: 2021/11/21 17:53:57 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cursor;

	if (lst)
	{
		while (*lst)
		{
			cursor = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = cursor;
		}
	}	
}
