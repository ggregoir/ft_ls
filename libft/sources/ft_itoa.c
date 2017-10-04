/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:45:00 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:31 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chars(int n)
{
	int c;

	c = (n < 0) ? 2 : 1;
	while (n && (n /= 10))
		c++;
	return (c);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		index;

	index = 0;
	ret = ft_strnew(chars(n));
	if (!ret)
		return (NULL);
	neg = (n < 0) ? 1 : 0;
	while (n)
	{
		ret[index++] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (neg)
		ret[index++] = '-';
	if (ret[0] == 0)
		ret[0] = '0';
	return (ft_strrev(ret));
}
