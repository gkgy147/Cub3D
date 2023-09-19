/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 23:38:20 by grobert           #+#    #+#             */
/*   Updated: 2023/09/19 12:01:47 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
s_c.x -> cos of alpha
s_c.y -> sin of alpha
*/
void	ft_draw_line(t_game *g)
{
	double	length;
	double	d[2];
	double	i;
	t_vect	s_c;

	g->pwd = (g->sdx - g->ddx) * (!g->side) + (g->sdy - g->ddy) * (g->side);
	d[0] = (g->ray.x * g->pwd) * BLOCK;
	d[1] = (g->ray.y * g->pwd) * BLOCK;
	length = sqrt(d[0] * d[0] + d[1] * d[1]);
	s_c.x = cos(atan(d[1] / d[0]) + M_PI * (d[0] < 0));
	s_c.y = sin(atan(d[1] / d[0]) + M_PI * (d[0] < 0));
	i = -1;
	while (++i < length)
		*(unsigned int *)((char *)(g->map.addr
					+ (((int)(g->pos.x * BLOCK + i * s_c.x))
						* (g->map.bpp / 8) + ((int)(g->pos.y * BLOCK + i
								* s_c.y)) * g->map.ll))) = MM_CV;
	return ;
}

void	ft_check_boundary(t_game *game)
{
	if (ft_in(game->pars.mat[(int) game->pos.y][(int)game->pos.x + 1], WALLS)
			&& game->pos.x > (int)game->pos.x + 1 - 0.50f)
		game->pos.x = (int)game->pos.x + 1 - 0.50f;
	if (ft_in(game->pars.mat[(int) game->pos.y][(int)game->pos.x - 1], WALLS)
			&& game->pos.x < (int)game->pos.x + 0.50f)
		game->pos.x = (int)game->pos.x + 0.50f;
	if (ft_in(game->pars.mat[(int) game->pos.y + 1][(int)game->pos.x], WALLS)
			&& game->pos.y > (int)game->pos.y + 1 - 0.50f)
		game->pos.y = (int)game->pos.y + 1 - 0.50f;
	if (ft_in(game->pars.mat[(int) game->pos.y - 1][(int)game->pos.x], WALLS)
			&& game->pos.y < (int)game->pos.y + 0.50f)
		game->pos.y = (int)game->pos.y + 0.50f;
	if (ft_in(game->pars.mat[(int) game->pos.y][(int)game->pos.x], "1D"))
	{
		if (game->pos.y - (int)game->pos.y > 0.5f)
			game->pos.y = (int)game->pos.y + 1.5f;
		else
			game->pos.y = floor(game->pos.y) - 0.5f;
		if (game->pos.x - (int)game->pos.x > 0.5f)
			game->pos.x = (int)game->pos.x + 1.5f;
		else
			game->pos.x = floor(game->pos.x) - 0.5f;
	}
	return ;
}

void	ft_move(t_game *game)
{
	if (game->move_x == 1)
	{
		game->pos.x += ((-1) * game->dir.y * 5.0f / game->fps);
		game->pos.y += (game->dir.x * 5.0f / game->fps);
	}
	if (game->move_x == -1)
	{
		game->pos.x += (game->dir.y * 5.0f / game->fps);
		game->pos.y += ((-1) * game->dir.x * 5.0f / game->fps);
	}
	if (game->move_y == 1)
	{
		game->pos.y += (game->dir.y * 5.0f / game->fps);
		game->pos.x += (game->dir.x * 5.0f / game->fps);
	}
	if (game->move_y == -1)
	{
		game->pos.y += ((-1) * game->dir.y * 5.0f / game->fps);
		game->pos.x += ((-1) * game->dir.x * 5.0f / game->fps);
	}
	ft_check_boundary(game);
	return ;
}
