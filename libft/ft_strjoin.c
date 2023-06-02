/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:50:22 by wfan              #+#    #+#             */
/*   Updated: 2022/11/27 18:57:06 by wfan             ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str_new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_new)
		return (NULL);
	while (s1[i])
	{
		str_new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_new[i + j] = s2[j];
		j++;
	}
	str_new[i + j] = '\0';
	return (str_new);
}
