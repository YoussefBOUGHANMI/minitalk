/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:04:33 by youssef           #+#    #+#             */
/*   Updated: 2021/11/15 21:13:45 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	len_dst;

	if (!s)
		return (NULL);
	i = 0;
	len_dst = ft_strlen(s + start);
	if (len > len_dst)
		dst = malloc((len_dst + 1) * sizeof(char));
	else
		dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[start + i] && i < len && start < ft_strlen((char *)s))
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
