/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:36:36 by wfan              #+#    #+#             */
/*   Updated: 2022/12/02 15:53:22 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}*/

char	*ft_strdup(const char *s)
{
	char	*str_cpy;
	int		i;
	size_t	len;

	len = 0;
	if (s)
		len = ft_strlen(s);
	str_cpy = malloc(len + 1);
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_cpy[i] = s[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
/*
int	main(void)
{
	ft_strdup("12345abcd");
	return (0);
}*/
