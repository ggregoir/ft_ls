/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:45:14 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:31 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_back(t_list **alst, t_list *new)
{
	t_list	*curr;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		curr = *alst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
