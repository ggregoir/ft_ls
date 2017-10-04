/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:58:31 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:53 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	index;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		index = 0;
		while (big[index] == little[index])
			if (!little[++index])
				return ((char *)big);
		big++;
	}
	return (0);
}
