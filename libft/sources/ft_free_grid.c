/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:23:07 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:16:12 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_free_grid(void ***grid)
{
	int	i;

	i = 0;
	if (grid == NULL)
		return ;
	while (*grid[i] != NULL)
	{
		ft_strdel(*grid[i]);
		i++;
	}
	*grid = NULL;
}
