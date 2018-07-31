/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 00:45:01 by chadams           #+#    #+#             */
/*   Updated: 2018/07/06 01:16:17 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	print_file(int fd)
{
	static char	*buffer;

	if (!fd || fd < 0)
		return (-1);
	while (get_next_line(fd, &buffer) != 0)
	{
		ft_putstr(buffer);
		ft_putchar('\n');
	}
	return (0);
}
