/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:31:46 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:47 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_strjoinf(char const *s1, char const *s2, int flag)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (flag == 1)
		ft_strdel((char**)&s1);
	if (flag == 2)
		ft_strdel((char**)&s2);
	if (flag == 3)
	{
		ft_strdel((char**)&s1);
		ft_strdel((char**)&s2);
	}
	return (str);
}
