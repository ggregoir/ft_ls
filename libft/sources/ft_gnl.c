/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 14:24:18 by ggregoir          #+#    #+#             */
/*   Updated: 2017/08/01 00:12:28 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <fcntl.h>

int					ft_gnl(int const fd, char **line)
{
	static char		*save[OPEN_MAX];
	t_gnl			gnl;

	if (!line || fd < 0 || !BUFF_SIZE || fd > OPEN_MAX)
		return (-1);
	gnl.ret = 1;
	if (!save[fd])
		save[fd] = ft_strnew(0);
	while (gnl.ret > -1)
	{
		if ((gnl.tmp = ft_strchr(save[fd], '\n')) ||
				((gnl.tmp = ft_strchr(save[fd], '\0')) && !gnl.ret))
		{
			*(gnl.tmp) = '\0';
			*line = ft_strdup(save[fd]);
			ft_memmove(save[fd], gnl.tmp + 1, ft_strlen(gnl.tmp + 1) + 1);
			save[fd] = (!gnl.ret) ? NULL : save[fd];
			return (line[0][0] || (!line[0][0] && gnl.ret > 0));
		}
		if ((gnl.ret = read(fd, gnl.buff, BUFF_SIZE)) == -1)
			return (-1);
		gnl.buff[gnl.ret] = '\0';
		save[fd] = ft_strjoinf(save[fd], gnl.buff, 1);
	}
	return (-1);
}
