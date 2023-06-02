/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:52:12 by wfan              #+#    #+#             */
/*   Updated: 2022/12/09 15:09:54 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
/*size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	while (tmp && n != 0)
	{
		tmp[i] = 0;
		n--;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	max = SIZE_MAX / nmemb;
	if (size > max)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			l;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup("\0"));
	if (l < len)
		sub = (char *)ft_calloc(l + 1, sizeof(char));
	else
		sub = (char *)ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (start <= i && j < len)
			sub[j++] = s[i];
		i++;
	}
	return (sub);
}
/*
#include <stdio.h>
int	main ()
{
	char *s;
	s = ft_substr("1", 420000, 4200000);
	printf("%s\n", s);
	free (s);
	return (0);
}*/
