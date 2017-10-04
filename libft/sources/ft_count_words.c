/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:41:44 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:26 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(const char *str, char c)
{
	int i;

	i = 0;
	if (*str == c)
		return (-1);
	while (*str)
	{
		while (*str && *str != c)
			str++;
		if (*str == c)
		{
			str++;
			if (*str == c)
				return (-1);
		}
		i++;
	}
	if (*str == c)
		return (-1);
	return (i);
}
