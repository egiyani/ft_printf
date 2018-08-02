/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:25:15 by egiyani           #+#    #+#             */
/*   Updated: 2018/08/01 18:25:22 by egiyani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_all(char const *s)
{
	char	*new_str;
	int		new_len;
	int		index;

	index = 0;
	new_len = (ft_strlen(s) + 1) - (ft_count_white((char *)s));
	new_str = (char *)malloc(sizeof(char) * new_len);
	if (new_str == NULL)
		return (NULL);
	ft_bzero(new_str, new_len);
	while (*s)
	{
		while (ft_isspace(*s) == 1)
			++s;
		new_str[index] = *s;
		++s;
		++index;
	}
	return (new_str);
}
