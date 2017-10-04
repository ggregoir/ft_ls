/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:49:43 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:36 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t x;

	x = -1;
	while (++x < n)
		if (((t_byte *)s1)[x] != ((t_byte *)s2)[x])
			return (((t_byte *)s1)[x] - ((t_byte *)s2)[x]);
	return (0);
}
