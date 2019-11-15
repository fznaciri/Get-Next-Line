/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:53:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/11/13 14:05:24 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_errors(int fd, char **buffer)
{
	if (!(*buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (!(BUFFER_SIZE >= 1) || (read(fd, *buffer, 0)) < 0)
	{
		free(*buffer);
		return (NULL);
	}
	return (*buffer);
}

char	*extract_line(char **str, char **line)
{
	char			*s;
	char			*tmp;

	if ((s = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, s - *str);
		tmp = *str;
		*str = ft_strdup(s + 1);
		free(tmp);
		return (*line);
	}
	return (NULL);
}

int		read_line(int fd, char **str)
{
	char			*buffer;
	char			*tmp;
	int				rd;

	if (!(check_errors(fd, &buffer)))
		return (-1);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buffer);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buffer);
	return (rd);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[MAX_OPEN];
	int				rd;

	if (!line || (rd = read_line(fd, &str[fd]) < 0))
		return (-1);
	if ((*line = extract_line(&str[fd], line)))
		return (1);
	if (!rd && str[fd])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}
