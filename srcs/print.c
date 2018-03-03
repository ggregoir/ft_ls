/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:20:51 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/28 23:45:39 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		printres(t_order *ord, t_flags *f)
{
	while (ord->next != NULL)
	{
		ft_putstr(ord->name);
		ord = ord->next;
		if (f->flags[LINE] == 1 && ord->name[0] != 0)
			write(1, "\n", 1);
		else if (ord->name[0] != 0)
			write(1, "	", 1);
	}
	write(1, "\n", 1);
}
