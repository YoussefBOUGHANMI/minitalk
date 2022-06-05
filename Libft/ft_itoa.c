/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:08:56 by youssef           #+#    #+#             */
/*   Updated: 2021/11/15 21:05:49 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	len_n(int n)
{
	int	i;

	i = 1;
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	neg_case(long *n, int *stop, int *len, char *a)
{
	if (!a)
		return ;
	*n = *n * -1;
	*stop = 1;
	*len = *len + 1;
	a[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*a;
	long	new_n;
	int		len;
	int		stop;

	new_n = n;
	stop = 0;
	len = len_n(n);
	if (new_n < 0)
	{
		a = malloc((len + 2) * sizeof(char));
		neg_case(&new_n, &stop, &len, a);
	}
	else
		a = malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[len--] = 0;
	while (len >= stop)
	{
		a[len--] = (new_n % 10) + 48;
		new_n = new_n / 10;
	}
	return (a);
}
