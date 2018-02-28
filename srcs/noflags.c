/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noflags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:24:09 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/28 21:37:33 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static inline void		handle_maj(struct dirent *dir, t_liste *lst, int *maji)
{
	int	i;

	i = 0;
	if (*maji == 0)
	{
		*maji = 1;
	}
	while (dir->d_name[i])
	{
		lst->maj->name[i] = dir->d_name[i];
		i++;
	}
	lst->maj->name[i] = '\0';
	i = -1;
	addord(&lst->maj);
	lst->maj = lst->maj->next;
}

static inline void		handle_dir(struct dirent *dir, t_liste *lst)
{
	int i;

	i = 0;
	while (dir->d_name[i])
	{
			lst->ord->name[i] = dir->d_name[i];
			i++;
	}
	lst->ord->name[i] = '\0';
	addord(&lst->ord);
	lst->ord = lst->ord->next;
}

static inline void		preprint(int maji, t_liste lst, t_flags *f)
{
	if (maji == 1)
	{
		lst.maj->next = lst.start;
		printres(lst.mstart, f);
	}
	else
		printres(lst.start, f);
}

void		noflags(char *path, t_flags *f)
{
	DIR				*d;
	struct dirent	*dir;
	int maji;
	t_liste lst;

	maji = 0;
	init_list(&lst);

	if ((d = opendir(path)) == NULL)
		patherror(path);
	if(d)
	{
		while((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] != '.')
			{
				if (dir->d_name[0] >= 'A' && dir->d_name[0] <= 'Z')
					handle_maj(dir, &lst, &maji);
				else
					handle_dir(dir, &lst);
			}
		}
		preprint(maji, lst, f);
	}
	closedir(d);
}