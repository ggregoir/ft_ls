/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:51:16 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

#define HEX "0123456789abcdef"

static void	ft_putchar_unprintable(char c)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
		write(1, ".", 1);
}

static void	print_byte(unsigned char c)
{
	ft_putchar(HEX[(c >> 4) % 16]);
	ft_putchar(HEX[c % 16]);
}

static void	print_char_line(const void *addr, size_t size)
{
	size_t x;

	x = -1;
	while (++x < ((size > 16) ? 16 : size))
		ft_putchar_unprintable(*(char *)(addr + x));
	ft_putchar('\n');
}

static void	print_byte_line(const void *addr, size_t size)
{
	size_t x;

	x = -1;
	while (++x < 16 && size - x)
	{
		print_byte(*(unsigned char *)(addr + x));
		if (x % 2)
			ft_putchar(' ');
	}
	if (size < 16)
	{
		x = 0;
		while (x++ < ((16 - size) * 2) + ((16 - size) / 2))
			ft_putchar(' ');
		if (size % 2)
			ft_putchar(' ');
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	while (size > 0)
	{
		print_byte_line(addr, size);
		print_char_line(addr, size);
		addr += 16;
		size = (size - 16 < size) ? size - 16 : 0;
	}
}
