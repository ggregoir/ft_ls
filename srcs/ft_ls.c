/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:49:39 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/28 21:29:28 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int			main(int argc, char **argv)
{
	t_flags f;

	if (argc > 1)
		handle_flags(&f, argv, argc);
	else
		noflags(".", &f);
	return 0;
}