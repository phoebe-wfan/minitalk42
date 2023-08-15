/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:47:30 by wfan              #+#    #+#             */
/*   Updated: 2023/08/15 17:14:36 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>

# include "./libft/libft.h"

void	ft_exit_failure_with_msg(char *message);
void	send_0(int pid);
void	send_1(int pid);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);

# define GREEN			"\x1b[32m"
# define RED			"\x1b[31m"
# define RESET			"\x1b[0m"

# define FT_SUCCESS		1
# define FT_ERROR		-1
# define FT_EOF			0

typedef int	t_bool;
# define FT_TRUE		1
# define FT_FALSE		0

#endif
