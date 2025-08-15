/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:07:05 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/15 13:07:05 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	while (i < slen + 1)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}
