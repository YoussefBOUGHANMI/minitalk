/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Youssef <youssef.boughanmi.pro@gmail.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:29:46 by Youssef           #+#    #+#             */
/*   Updated: 2022/06/05 21:02:36 by Youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <signal.h>

void	pid_srv_error(void)
{
	ft_putstr_fd("error pid serveur\n", 1);
	exit(0);
}

void	send_char(int pid_srv, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid_srv, SIGUSR1) == -1)
				pid_srv_error();
		}
		else
		{
			if (kill(pid_srv, SIGUSR2) == -1)
				pid_srv_error();
		}
		usleep(100);
		i--;
	}
}

void	send_message(int pid_srv, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid_srv, message[i]);
		i++;
	}
	send_char(pid_srv, '\n');
}

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr_fd("Message reçu par le serveur\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_putstr_fd(" il faut 2 arguments : pid du server et le message", 1);
	else if (ft_atoi(argv[1]) <= 0)
		pid_srv_error();
	else
	{
		signal(SIGUSR1, handler);
		send_message(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
}
