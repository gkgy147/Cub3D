/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:05:40 by grobert           #+#    #+#             */
/*   Updated: 2023/09/16 19:05:52 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char const *str)
{
	char	*out;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i])
		i++;
	out = (char *)malloc((i + 1) * sizeof(char));
	if (!out)
		return (0);
	i = -1;
	while (str && str[++i])
		out[i] = str[i];
	out[i] = 0;
	return (out);
}

