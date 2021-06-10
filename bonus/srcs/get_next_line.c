/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:05:54 by vintran           #+#    #+#             */
/*   Updated: 2021/06/10 17:37:58 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*join_loop(char *s1, char *s2, int reslen)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(reslen);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*join_buf(char *s1, char *s2)
{
	char	*res;
	int		reslen;

	if (!s1 && !s2)
		return (NULL);
	reslen = ft_sstrlen(s1) + ft_sstrlen(s2) + 1;
	res = join_loop(s1, s2, reslen);
	if (!res)
		return (NULL);
	free(s1);
	return (res);
}

char	*maj_file(char *file, int newline)
{
	char	*res;
	int		restlen;

	restlen = ft_sstrlen(file + newline);
	res = ft_strndup(file + newline, restlen);
	if (!res)
		return (NULL);
	free(file);
	return (res);
}

char	*get_line(char **file)
{
	char	*res;
	int		i;

	i = 0;
	while ((*file)[i] && (*file)[i] != '\n')
		i++;
	res = ft_strndup(*file, i);
	if (!res)
		return (NULL);
	if ((*file)[i] != '\n')
		i--;
	*file = maj_file(*file, i + 1);
	if (!(*file))
		return (NULL);
	return (res);
}

int	get_next_line(int fd, char **line, char **file)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	while (ret && !is_newline(*file))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		*file = join_buf(*file, buf);
		if (!(*file))
			return (-1);
	}
	*line = get_line(file);
	if (!(*line))
		return (-1);
	if (ret == 0)
	{
		free(*file);
		return (ret);
	}
	return (1);
}
