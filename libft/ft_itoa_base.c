/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:55:25 by chadams           #+#    #+#             */
/*   Updated: 2018/07/06 01:53:03 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	nbr_len(int nbr, int base)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= base;
		++len;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	char	*base_str;
	long	nbr;
	int		len;

	if (value == 0)
		return ("0");
	nbr = value;
	base_str = "0123456789ABCDEF";
	len = nbr_len(nbr, base);
	if (value < 0)
	{
		if (base == 10)
			++len;
		nbr *= -1;
	}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[len] = '\0';
	while ((str[--len] = base_str[nbr % base]) && (nbr /= base))
		;
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
