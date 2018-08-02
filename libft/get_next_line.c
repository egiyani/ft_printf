/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:25:39 by egiyani           #+#    #+#             */
/*   Updated: 2018/08/01 18:25:41 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **str, char **line)
{
	size_t	index;
	char	*temp_buf;

	index = 0;
	while ((*str)[index])
	{
		if ((*str)[index] == '\n')
		{
			temp_buf = *str;
			*line = ft_strsub(*str, 0, index);
			*str = ft_strsub(*str, index + 1, ft_strlen(*str) - index);
			free(temp_buf);
			return (1);
		}
		++index;
	}
	return (0);
}

static int	end_file(char *str, char **line)
{
	if (*str)
	{
		*line = ft_strdup(str);
		ft_strclr(str);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp_buf;
	static char	*str;

	temp_buf = ft_strnew(BUFF_SIZE);
	if (!str)
		str = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || (read(fd, temp_buf, 0) < 0))
		return (-1);
	if (get_line(&str, line))
		return (1);
	while ((ret = read(fd, temp_buf, BUFF_SIZE)) > 0)
	{
		temp_buf[ret] = '\0';
		str = ft_strjoin_memdel(str, temp_buf);
		if (get_line(&str, line))
		{
			free(temp_buf);
			return (1);
		}
	}
	if (end_file(str, line))
		return (1);
	return (0);
}
