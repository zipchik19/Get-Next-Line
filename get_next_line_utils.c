/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:22 by ziharuty          #+#    #+#             */
/*   Updated: 2023/03/04 14:55:58 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	a = (char)c;
	i = 0;
	while (s && (s[i] || a == 0))
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1 != 0 && s1[j] != '\0')
		result[i++] = s1[j++];
	j = 0;
	while (s2 != 0 && s2[j] != '\0')
		result[i++] = s2[j++];
	result[i++] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*src;
	char	*dest;

	src = (char *)s;
	len = ft_strlen(src);
	dest = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
