/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:49:39 by ggregoir          #+#    #+#             */
/*   Updated: 2017/10/04 21:59:03 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

/*void		init_opt
{

}
*/
void		flags(int argc, char **argv)
{
	//init_opt();
	DIR			*d;
	struct dirent *dir;

	d = opendir(argv[argc - 1]);
	if(d)
	{
		while((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.')
			ft_putendl(dir->d_name);
	}
	closedir(d);
}
void		noflags()
{
	DIR			*d;
	struct dirent *dir;

	d = opendir(".");
	if(d)
	{
		while((dir = readdir(d)) != NULL)
			if (dir->d_name[0] != '.')
			ft_putendl(dir->d_name);
	}
	closedir(d);
}

int			main(int argc, char **argv)
{
	//t_opt[5] 	opt;
	//t_path		p;

	
	if (argc > 1)
		flags(argc, argv);
	else
		noflags();
	return 0;
}