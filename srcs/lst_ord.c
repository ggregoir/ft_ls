/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:22:20 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/28 21:59:13 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		addord(t_order **ord)
{
	t_order		*new;

	if (!(new = malloc(sizeof(*new))))
		exit(1);
	new->next = NULL;
	ft_bzero((void*)&new->name, 255); 
	(*ord)->next = new;
}

void		init_list(t_liste *lst)
{
	if (!(lst->ord = malloc(sizeof(*lst->ord))))
		exit(0);
	if (!(lst->maj = malloc(sizeof(*lst->maj))))
		exit(0);
	if (!(lst->dot = malloc(sizeof(*lst->dot))))
		exit(0);
	lst->start = lst->ord;
	lst->mstart = lst->maj;
	lst->dstart = lst->dot;
}