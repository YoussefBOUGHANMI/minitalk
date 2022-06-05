/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboughan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:20:18 by yboughan          #+#    #+#             */
/*   Updated: 2021/10/31 15:08:46 by yboughan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	str_c;

	i = 0;
	str_c = c;
	while (i < len)
	{
		*(unsigned char *)(b + i) = str_c;
		i++;
	}
	return (b);
}
