/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:20:18 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/03 17:30:27 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	patherror(char *path)
{
	write(2, "ft_ls: ", 7);
	ft_putstr_fd(path, 2);
	write(2, ": No such file or directory\n", 28);
}
