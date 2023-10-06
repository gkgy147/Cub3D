/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:30:06 by grobert           #+#    #+#             */
/*   Updated: 2023/10/06 15:42:45 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_pars(t_game *game)
{
	int	i;

	game->pars.game = game;
	game->pars.line = NULL;
	game->pars.mat = NULL;
	game->pars.width = 0;
	game->pars.height = 0;
	game->pars.offset = 0;
	game->no.img = NULL;
	game->so.img = NULL;
	game->we.img = NULL;
	game->ea.img = NULL;
	game->dr.img = NULL;
	game->no.w = 0;
	game->no.h = 0;
	game->so.w = 0;
	game->so.h = 0;
	game->we.w = 0;
	game->we.h = 0;
	game->ea.w = 0;
	game->ea.h = 0;
	i = 0;
	while (i < 6)
		game->pars.ids[i++] = NULL;
	return ;
}

void	ft_init(t_game *game)
{
	game->p = -1;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->addr = NULL;
	game->ot = 0;
	game->move_x = 0;
	game->move_y = 0;
	game->rotate = 0;
	game->z = 1;
	game->x = WIDTH / 2;
	game->pos.x = -1;
	game->pos.y = -1;
	game->dir.x = 0;
	game->dir.y = 0;
	game->cam.x = 0;
	game->cam.y = 0;
	ft_init_pars(game);
	return ;
}
