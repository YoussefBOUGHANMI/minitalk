/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:55:11 by youssef           #+#    #+#             */
/*   Updated: 2021/11/15 21:11:10 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	word_count(char const *s, char c, int *nb_word)
{
	int	first_word;

	first_word = 1;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (*(s - 1) == c || first_word)
			{
				*nb_word = *nb_word + 1;
				first_word = 0;
			}
			s++;
		}	
	}
	return (0);
}

char const	*ft_cp(char const *s, char c, char **new_word)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*new_word = ft_substr(s, 0, i);
	return (s + i);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		nb_word;
	int		p_word;

	if (!s)
		return (NULL);
	nb_word = 0;
	p_word = 0;
	word_count(s, c, &nb_word);
	dst = malloc((nb_word + 1) * sizeof (char *));
	if (!dst)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			s = ft_cp(s, c, &dst[p_word]);
			p_word = p_word + 1;
		}
	}
	dst[p_word] = 0;
	return (dst);
}
