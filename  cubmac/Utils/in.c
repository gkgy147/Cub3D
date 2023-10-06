/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 03:19:44 by grobert           #+#    #+#             */
/*   Updated: 2023/10/06 15:44:43 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_count(char c, char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == c)
			j++;
	return (j);
}

/*
RETURN
[1] if c is in chars
[0] if c is not in chars
*/
int	ft_in(char c, const char *chars)
{
	int	i;

	i = 0;
	while (chars[i])
	{
		if (chars[i] == c)
			return (1);
		i++;
	}
	return (0);
}
