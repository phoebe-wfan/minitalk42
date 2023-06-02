/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:04:01 by wfan              #+#    #+#             */
/*   Updated: 2022/12/02 16:03:05 by wfan             ###   ########.fr       */
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
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*s2;

    i = 0;
	s2 = (char *)s;
	if (!s2)
		return (NULL);
	else
	{
		while (s2[i] != c)
		{
			if (s2[i] == '\0')
				return (NULL);
			i++;
		}
		return (&s2[i]);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_sub;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	str_sub = malloc(len + 1);
	if (!str_sub)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len && start < ft_strlen((const char *)str))
	{
		str_sub[i] = str[start + i];
		i++;
	}
	str_sub[i] = '\0';
	return (str_sub);
}

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
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str_new;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len]) && len)
		len--;
	str_new = ft_substr(s1, 0, len + 1);
	if (!str_new)
		return (NULL);
	return (str_new);
}
