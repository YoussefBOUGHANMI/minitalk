/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:17:24 by youssef           #+#    #+#             */
/*   Updated: 2021/11/15 21:22:08 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cursor;
	int		i;

	i = 0;
	cursor = lst;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}
