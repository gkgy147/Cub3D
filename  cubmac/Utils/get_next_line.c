/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:31:44 by grobert           #+#    #+#             */
/*   Updated: 2023/09/19 12:06:16 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(*buff))
		r = read(fd, buff, BUFFER_SIZE);
	else
		r = ft_strlen(buff);
	str = ft_get_first_str(buff);
	while (r && !ft_nlinstr(str))
	{
		if (r <= 0)
			break ;
		if (!(*buff))
			r = read(fd, buff, BUFFER_SIZE);
		if (r <= 0)
			break ;
		str = ft_realloc_get(str, buff);
	}
	if (str && *str)
		return (str);
	free(str);
	return (0);
}
