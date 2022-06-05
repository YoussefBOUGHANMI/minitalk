/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:11:41 by youssef           #+#    #+#             */
/*   Updated: 2021/11/13 10:55:09 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s1);
	s2 = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!s2)
		return (NULL);
	while (s1[i])
	{	
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
