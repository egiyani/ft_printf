/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:32:28 by chadams           #+#    #+#             */
/*   Updated: 2018/07/06 02:39:06 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!s1)
		return (NULL);
	dup = ft_strndup(s1, ft_strlen(s1));
	if (dup == NULL)
		return (NULL);
	return (dup);
}
