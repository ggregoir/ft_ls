/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:50:15 by ggregoir          #+#    #+#             */
/*   Updated: 2017/10/04 21:49:38 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include "libft/includes/libft.h"

typedef	struct	s_path
{	
	char *path;
}				t_path;

typedef	struct	s_opt
{	
	char		c;
	int			(*ptr)();
}				t_opt;

#endif