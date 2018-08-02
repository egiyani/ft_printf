/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiyani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:23:25 by egiyani           #+#    #+#             */
/*   Updated: 2018/08/01 18:23:29 by egiyani          ###   ########.fr       */
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
