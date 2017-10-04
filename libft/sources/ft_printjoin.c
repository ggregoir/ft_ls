/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:51:35 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printjoin(char *delim, char **arr, size_t size)
{
	if (!arr || !*arr)
		return ;
	while (size--)
	{
		ft_putstr(*arr++);
		if (size >= 1)
			ft_putstr(delim);
	}
}
