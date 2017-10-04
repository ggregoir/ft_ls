/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:52:20 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb * -1 != nb)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb % 10 != nb)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 > 0 ? nb % 10 + '0' : nb % 10 * (-1) + '0', fd);
}
