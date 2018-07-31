/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chadams <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:42:03 by chadams           #+#    #+#             */
/*   Updated: 2018/07/06 00:00:43 by chadams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	check_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && '9' >= c);
	return ((c >= '0' && '9' >= c) || (c >= 'A' && 'F' >= c)
			|| (c >= 'a' && 'f' >= c));
}

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	if (base < 2 || base > 16)
		return (0);
	while (ft_isspace(i))
		++i;
	if (str[i] == '-' && base == 10)
		nbr *= -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && check_base(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		++i;
	}
	return (nbr);
}
