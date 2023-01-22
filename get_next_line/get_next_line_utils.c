/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cembolat <cembolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:47:09 by cbolat            #+#    #+#             */
/*   Updated: 2023/01/22 18:29:17 by cembolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "get_next_line.h"

size_t	ft_get_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_get_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strconcat(char *d_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!d_line)
	{
		d_line = (char *)malloc(1 * sizeof(char));
		d_line[0] = '\0';
	}
	if (!d_line || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_get_strlen(d_line) + ft_get_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (d_line)
		while (d_line[++i] != '\0')
			str[i] = d_line[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_get_strlen(d_line) + ft_get_strlen(buff)] = '\0';
	free(d_line);
	return (str);
}

char	*ft_get_line(char *d_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!d_line[i])
		return (NULL);
	while (d_line[i] && d_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (d_line[i] && d_line[i] != '\n')
	{
		str[i] = d_line[i];
		i++;
	}
	if (d_line[i] == '\n')
	{
		str[i] = d_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_dinamic_line(char *d_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (d_line[i] && d_line[i] != '\n')
		i++;
	if (!d_line[i])
	{
		free(d_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_get_strlen(d_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (d_line[i])
		str[j++] = d_line[i++];
	str[j] = '\0';
	free(d_line);
	return (str);
}
