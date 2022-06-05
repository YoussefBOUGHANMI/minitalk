/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:00:48 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/05 21:41:50 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "libft.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;

	(void)context;
	c |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == 10)
			kill(info->si_pid, SIGUSR1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{	
	struct sigaction	sa;

	ft_putstr_fd("Welcome :) \npid server : ", 1);
	ft_putstr_fd(ft_itoa(getpid()), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
