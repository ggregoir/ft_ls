/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 11:47:05 by ggregoir          #+#    #+#             */
/*   Updated: 2017/09/16 16:30:29 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_color(char *color, char *str, char *end)
{
	ft_putstr(color);
	ft_putstr(str);
	if (end != NULL)
		ft_putstr(end);
}

void		ft_colorendl(char *color, char *str, char *end)
{
	ft_color(color, str, end);
	write(1, "\n", 1);
}
