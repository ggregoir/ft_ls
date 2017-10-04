/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:22:53 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_free_strsplit(char *s, char **buff, char split)
{
	int x;
	int len;

	len = ft_count_words(s, split);
	x = -1;
	while (++x < len)
		free(buff[x]);
	free(buff);
}
