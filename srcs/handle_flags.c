/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:51:13 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/03 18:26:59 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		wich_flag(t_flags *f, char c)
{
			if (c == 'R')
			{
				ft_putendl("R");
				f->flags[REC] = 1;
			}
			if (c == 'a')
				f->flags[DOT] = 1;
			if (c == 'l')
			{
				ft_putendl("l");
				f->flags[LOWL] = 1;
			}
			if (c == 'r')
			{
				ft_putendl("r");
				f->flags[REV] = 1;
			}
			if (c == 't')
			{
				ft_putendl("t");
				f->flags[TIME] = 1;
			}
			if (c == '1')
				f->flags[LINE] = 1;
}

static void		get_flags(t_flags *f, char *argv)
{
	int i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i] == 'R' || argv[i] == 'l' || argv[i] == 'a' ||
			argv[i] == 'r' || argv[i] == 't' || argv[i] == '1')
			wich_flag(f, argv[i]);
		else
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(argv[i]);
			ft_putendl("\nusage: ls [-Ralrt1] [file ...]");
			exit(1);
		}
	}
}

static	void	init_flags(t_flags *f)
{
	f->flags[REC] = 0;
	f->flags[DOT] = 0;
	f->flags[LOWL] = 0;
	f->flags[REV] = 0;
	f->flags[TIME] = 0;
	f->flags[LINE] = 0;
}

static void		exec_flags(t_flags *f, char *path)
{
	if (f->flags[DOT] == 1)
		dotfiles(path, f);
	else if (f->flags[DOT] == 0 && f->flags[LINE] == 1)
		noflags(path, f);
	else
		noflags(path, f);
}

void			is_dir(char *str, int *i, t_flags *f)
{
	struct stat s;

	if (stat(str, &s) == -1)
		patherror(str);
	else if (S_ISDIR(s.st_mode))
	{
		if (*i == 1)
		{
			*i = 0;
			ft_putstr(str);
			write(1, ":\n", 2);
			exec_flags(f, str);
		}
		else
		{
			write(1, "\n", 2);
			ft_putstr(str);
			write(1, ":\n", 2);
			exec_flags(f, str);
		}
	}
	else
		ft_putendl(str);
}

void			is_dir_one(char *str, t_flags *f)
{
	struct stat s;

	if (stat(str, &s) == -1)
		patherror(str);
	if (S_ISDIR(s.st_mode))
			noflags(str, f);
	else
			ft_putendl(str);
}

void			handle_flags(t_flags *f, char **argv, int argc)
{
	int i;
	int flag;
	int first;

	first = 1;
	flag = 1;
	init_flags(f);
	i = 1;
	if (argc == 2 && argv[1][0] != '-')
		is_dir_one(argv[1], f);
	else
	{
		while (i < argc)
		{
			if(argv[i][0] == '-'&& flag == 1)
				get_flags(f, argv[i]);
			else
			{
				flag = 0;
				if (i == argc - 1)
					exec_flags(f, argv[i]);
				else
					is_dir(argv[i], &first, f);
			}
			i++;
		}
		if (argv[argc - 1][0] == '-')
			exec_flags(f, ".");
	}
}