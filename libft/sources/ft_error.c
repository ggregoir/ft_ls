/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 15:26:18 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void			ft_error(char *message)
{
	ft_putstr("Error: ");
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
