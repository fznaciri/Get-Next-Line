/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:47:45 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/30 20:49:28 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (((char*)s)[i] != '\0')
		i++;
	return (i);
}

char		*ft_strchr(const char *s, int c)
{
	char *cs;

	cs = (char*)s;
	if (!cs)
		return (NULL);
	if (c == '\0')
		return (cs + ft_strlen(s));
	else
		while (*cs != '\0')
		{
			if (*cs != c)
				cs++;
			else
				return (cs);
		}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	i = 0;
	j = 0;
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!(strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		strjoin[i] = ((char*)s1)[i];
		i++;
	}
	while (s2[j])
	{
		strjoin[i + j] = ((char*)s2)[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

char		*ft_strdup(const char *src)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strndup(const char *src, size_t n)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i] != '\0' && i < n)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
