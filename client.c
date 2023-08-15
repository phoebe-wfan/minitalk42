/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:47:12 by wfan              #+#    #+#             */
/*   Updated: 2023/06/02 14:47:16 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	ft_exit_failure_with_msg(char *message)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("<ERROR> ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}*/

void	send_0(int pid)
{
	if (kill(pid, SIGUSR1) == FT_ERROR)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("<ERROR> ", 2);
		ft_putstr_fd("Signal(SIGUSR1) transmission failed.\n", 2);
		ft_putstr_fd(RESET, 2);
		exit(EXIT_FAILURE);
	}	
}

void	send_1(int pid)
{
	if (kill(pid, SIGUSR2) == FT_ERROR)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("<ERROR> ", 2);
		ft_putstr_fd("Signal(SIGUSR2) transmission failed.\n", 2);
		ft_putstr_fd(RESET, 2);
		exit(EXIT_FAILURE);
	}	
}

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_putnbr_fd(received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				send_1(pid);
			else
				send_0(pid);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		send_0(pid);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
