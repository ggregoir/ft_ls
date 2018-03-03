/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:50:15 by ggregoir          #+#    #+#             */
/*   Updated: 2018/03/02 15:02:12 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include "libft/includes/libft.h"
# include <sys/stat.h>

# define	REC		0
# define	DOT		1
# define	LOWL	2
# define	REV		3
# define	TIME	4
# define	LINE	5

typedef	struct	s_path
{	
	char *path;
}				t_path;

typedef	struct	s_order t_order;
struct s_order
{	
	char 	name[255];
	t_order	*next;

};

typedef	struct	s_flags
{	
	int	flags[6];
}				t_flags;

typedef	struct	s_liste
{	
	t_order 		*ord;
	t_order			*start;
	t_order			*mstart;
	t_order			*maj;
	t_order			*dot;
	t_order			*dstart;
}				t_liste;

void		handle_flags(t_flags *f, char **argv, int argc);
void		printres(t_order *ord, t_flags *f);
void		addord(t_order **ord);
void		init_list(t_liste *lst);
void		noflags(char *path, t_flags *f);
void		dotfiles(char *path, t_flags *f);
void		patherror(char *path);

#endif