/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:38:37 by ziharuty          #+#    #+#             */
/*   Updated: 2023/03/04 14:55:44 by ziharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_str(char *str)
{
	free(str);
	str = 0;
}

char	*ft_read_str(int fd, char *leftstr)
{
	char	*buff;
	char	*str;
	int		rdbyte;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rdbyte = 1;
	while (!ft_strchr(leftstr, '\n') && rdbyte != 0)
	{
		rdbyte = read(fd, buff, BUFFER_SIZE);
		if (rdbyte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rdbyte] = '\0';
		str = ft_strdup(leftstr);
		free_str(leftstr);
		leftstr = ft_strjoin(str, buff);
		free_str(str);
	}
	free(buff);
	return (leftstr);
}

char	*ft_get_line(char *leftstr)
{
	int		i;
	char	*str;

	i = 0;
	if (!leftstr[i])
		return (NULL);
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (leftstr[i] && leftstr[i] != '\n')
	{
		str[i] = leftstr[i];
		i++;
	}
	if (leftstr[i] == '\n')
	{
		str[i] = leftstr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_new_line(char *leftstr)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (leftstr[i] && leftstr[i] != '\n')
		i++;
	if (!leftstr[i])
	{
		free(leftstr);
		return (NULL);
	}
	ptr = malloc((ft_strlen(leftstr) - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i++;
	j = 0;
	while (leftstr[i])
		ptr[j++] = leftstr[i++];
	ptr[j] = '\0';
	free(leftstr);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*leftstr[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	leftstr[fd] = ft_read_str(fd, leftstr[fd]);
	if (!leftstr[fd])
		return (NULL);
	line = ft_get_line(leftstr[fd]);
	leftstr[fd] = ft_get_new_line(leftstr[fd]);
	return (line);
}
