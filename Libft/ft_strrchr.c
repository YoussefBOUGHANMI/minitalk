/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:17:06 by youssef           #+#    #+#             */
/*   Updated: 2021/11/12 16:41:24 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen((char *)s);
	if ((char)c == 0)
		return ((char *)s + len);
	while (len > 0)
	{
		len --;
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
}
