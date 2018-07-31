/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 01:05:13 by chadams           #+#    #+#             */
/*   Updated: 2018/07/06 02:39:57 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;

	if (!s1 || !n)
		return (NULL);
	dup = ft_strnew(n);
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, s1, n);
	dup[n] = '\0';
	return (dup);
}
