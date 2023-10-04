/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:19:16 by grobert           #+#    #+#             */
/*   Updated: 2023/10/04 23:35:07 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void	ft_set_minimap(t_game *g)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	while (++i < g->map.h)
	{
		j = -1;
		while (++j < g->map.w)
		{
			dst = g->map.addr + (j * (g->map.bpp / 8) + i * g->map.ll);
			*(unsigned int *)dst = MM_BG;
			if (g->pars.mat[(int)(i / BLOCK)][(int)(j / BLOCK)] == 49)
				*(unsigned int *)dst = MM_WL;
			else if (powf((g->pos.x * BLOCK - j), 2)
				+ powf((g->pos.y * BLOCK - i), 2) <= 6.25f)
				*(unsigned int *)dst = MM_PC;
		}
	}
}

void	ft_prepare_dda(t_game *game)
{
	game->ddx = 1e30;
	game->ddy = 1e30;
	if (game->ray.x != 0)
		game->ddx = fabs(1 / game->ray.x);
	if (game->ray.y != 0)
		game->ddy = fabs(1 / game->ray.y);
	game->stepx = -1;
	game->stepy = -1;
	if (game->ray.x < 0)
		game->sdx = (game->pos.x - (int) game->pos.x) * game->ddx;
	else
	{
		game->stepx = 1;
		game->sdx = (1.0f + (int) game->pos.x - game->pos.x) * game->ddx;
	}
	if (game->ray.y < 0)
		game->sdy = (game->pos.y - (int) game->pos.y) * game->ddy;
	else
	{
		game->stepy = 1;
		game->sdy = (1.0f + (int) game->pos.y - game->pos.y) * game->ddy;
	}
}

void	ft_dda(t_game *g)
{
	g->hit = 0;
	g->posx = g->pos.x;
	g->posy = g->pos.y;
	while (!g->hit)
	{
		if (g->sdx < g->sdy)
		{
			g->sdx += g->ddx;
			g->posx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sdy += g->ddy;
			g->posy += g->stepy;
			g->side = 1;
		}
		if (ft_in(g->pars.mat[(int) g->posy][(int) g->posx], WALLS))
			g->hit = 1;
	}
	g->pwd = (g->sdx - g->ddx) * (!g->side) + (g->sdy - g->ddy) * (g->side);
	return ;
}