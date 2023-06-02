/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:19:23 by wfan              #+#    #+#             */
/*   Updated: 2022/12/02 13:24:40 by wfan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s2;

	if (!s)
		return (NULL);
	s2 = (unsigned char *)s;
	while (*s2)
	{
		if (*s2 == (unsigned char)c)
			return ((char *)s2);
		s2++;
	}
	if (c == 0)
		return ((char *)s2);
	return (NULL);
}
