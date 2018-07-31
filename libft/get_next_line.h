/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 11:25:02 by chadams           #+#    #+#             */
/*   Updated: 2018/07/05 20:52:22 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int	get_next_line(int fd, char **line);

# define BUFF_SIZE 32

#endif
