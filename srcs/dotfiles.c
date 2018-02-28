/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:13:55 by ggregoir          #+#    #+#             */
/*   Updated: 2018/02/28 22:00:32 by ggregoir         ###   ########.fr       */
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

static inline void		handle_dot(struct dirent *dir, t_liste *lst, int *doti)
{
	int	i;

	i = 0;
	if (*doti == 0)
	{
		*doti = 1;
	}
	while (dir->d_name[i])
	{
		lst->dot->name[i] = dir->d_name[i];
		i++;
	}
	lst->dot->name[i] = '\0';
	i = -1;
	addord(&lst->dot);
	lst->dot = lst->dot->next;
}

static inline void		preprint(int maji, int doti, t_liste lst, t_flags *f)
{
	if (doti == 1)
	{
		if (maji == 1)
		{
			lst.dot->next = lst.mstart;
			lst.maj->next = lst.start;
		}
		else
			lst.dot->next = lst.start;
		printres(lst.dstart, f);
	}
	else if (maji == 1)
	{
		lst.maj->next = lst.start;
		printres(lst.mstart, f);
	}
	else
		printres(lst.start, f);
}

void		dotfiles(char *path, t_flags *f)
{
	DIR				*d;
	struct dirent	*dir;
	int maji;
	int doti;
	t_liste lst;

	maji = 0;
	doti = 0;
	init_list(&lst);

	if ((d = opendir(path)) == NULL)
		patherror(path);
	if(d)
	{
		while((dir = readdir(d)) != NULL)
		{
			if (dir->d_name[0] == '.')
				handle_dot(dir, &lst, &doti);
			else if (dir->d_name[0] >= 'A' && dir->d_name[0] <= 'Z')
				handle_maj(dir, &lst, &maji);
			else
				handle_dir(dir, &lst);
		}
		preprint(maji, doti, lst, f);
	}
	closedir(d);
}