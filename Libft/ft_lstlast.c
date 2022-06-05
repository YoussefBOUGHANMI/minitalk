/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:22:38 by youssef           #+#    #+#             */
/*   Updated: 2021/11/15 21:29:12 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cursor;
	t_list	*last;

	cursor = lst;
	last = lst;
	while (cursor)
	{
		last = cursor;
		cursor = cursor->next;
	}
	return (last);
}
