/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:59:52 by wfan              #+#    #+#             */
/*   Updated: 2022/12/04 18:06:09 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar2(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putrecurs2(int n, int fd)
{
	char	chr;

	if (n == 0)
		return ;
	ft_putrecurs2(n / 10, fd);
	chr = '0' + n % 10;
	ft_putchar2(chr, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0 && n > -2147483648)
		{
			write(fd, "-", 1);
			ft_putrecurs2(-n, fd);
		}
		else if (n == -2147483648)
		{
			write(fd, "-", 1);
			write(fd, "2147483648", 10);
		}
		else
			ft_putrecurs2(n, fd);
	}
}
