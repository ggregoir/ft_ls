/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcont.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:45:48 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:32 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelcont(t_list **alst, void *cont)
{
	t_list	*prev;
	t_list	*current;

	if (!alst || !*alst)
		return ;
	prev = *alst;
	if (prev->data == cont)
	{
		*alst = prev->next;
		return ;
	}
	current = prev->next;
	while (current)
	{
		if (current->data == cont)
		{
			prev->next = current->next;
			free(current);
			free(cont);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
