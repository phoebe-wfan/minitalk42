/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 13:16:58 by wfan              #+#    #+#             */
/*   Updated: 2022/11/27 17:26:27 by wfan             ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*l;

	if (!big)
		return (NULL);
	if (!ft_strlen(little))
		return ((char *)big);
	i = 0;
	b = (char *)big;
	l = (char *)little;
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && i + j < len && l[j] != '\0')
			j++;
		if (l[j] == '\0')
			return (b + i);
		i++;
	}
	return (NULL);
}
