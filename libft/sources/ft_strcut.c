/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:02:19 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/08 16:01:10 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcut(char *str, int start, int end)
{
	int		i;
	char	*ret;

	i = 0;
	if ((ret = (char *)malloc(sizeof(*str) * ((end - start) + 1))) == NULL)
		return (NULL);
	while (start < end)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
