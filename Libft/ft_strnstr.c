/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:44:55 by youssef           #+#    #+#             */
/*   Updated: 2021/11/13 05:38:22 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] != needle[0] && i < len && haystack[i])
			i++;
		while (haystack[i + j] == needle[j] && needle[j]
			&& i + j < len && haystack[i + j])
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		if (haystack[i] != 0)
			i++;
	}
	return (NULL);
}
