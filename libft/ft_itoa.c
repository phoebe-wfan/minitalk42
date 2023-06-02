/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:14:24 by wfan              #+#    #+#             */
/*   Updated: 2022/11/27 19:18:07 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char	*str)
{
	int		i;
	int		size;
	char	tmp;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
	return (str);
}

static int	ft_intlen(int n)
{
	int		i;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_check(int n)
{
	char	*res;

	if (n == 0)
		return (ft_strdup("0"));
	res = malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!res)
		return (NULL);
	ft_bzero(res, ft_intlen(n) + 1);
	return (res);
}

char	*ft_itoa(int n)
{
	int				i;
	int				sign;
	unsigned int	nb;
	char			*res;

	res = ft_check(n);
	if (!res)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		nb = -n;
		sign = -1;
	}
	else
		nb = n;
	i = 0;
	while (nb)
	{
		res[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign == -1)
		res[i] = '-';
	return (ft_strrev(res));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
}
*/
