/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:05:05 by grobert           #+#    #+#             */
/*   Updated: 2023/10/06 15:44:53 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static size_t	ft_dim(int n)
{
	size_t	dim;

	if (!n)
		return (1);
	dim = 0;
	if (n < 0)
		dim++;
	while (n)
	{
		n /= 10;
		dim++;
	}
	return (dim);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	dim;
	int		m;

	dim = ft_dim(n);
	num = (char *) malloc((dim + 1) * sizeof (char));
	if (!num)
		return (0);
	num[dim] = 0;
	m = n;
	while (dim--)
	{
		num[dim] = ft_abs(n % 10) + 48;
		n /= 10;
	}
	if (m < 0)
		num[0] = '-';
	return (num);
}
