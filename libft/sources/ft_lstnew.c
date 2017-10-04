/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:47:21 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:34 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *data, size_t size)
{
	t_list *ret;

	ret = (t_list*)ft_memalloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	if (data == NULL)
	{
		ret->data = NULL;
		ret->size = 0;
	}
	else
	{
		ret->data = ft_memalloc(size);
		if (ret->data == NULL)
		{
			free(ret);
			return (NULL);
		}
		ft_memcpy(ret->data, data, size);
		ret->size = size;
	}
	ret->next = NULL;
	return (ret);
}
