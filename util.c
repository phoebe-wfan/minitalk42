/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:51:31 by wfan              #+#    #+#             */
/*   Updated: 2023/06/02 14:51:34 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_exit_failure_with_msg(char *message)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd("<ERROR> ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	send_0(int pid)
{
	if (kill(pid, SIGUSR1) == FT_ERROR)
		ft_exit_failure_with_msg("Signal(SIGUSR1) transmission failed.");
}

void	send_1(int pid)
{
	if (kill(pid, SIGUSR2) == FT_ERROR)
		ft_exit_failure_with_msg("Signal(SIGUSR2) transmission failed.");
}
