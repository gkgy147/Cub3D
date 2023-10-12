/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <georgerobert147@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:59:53 by grobert           #+#    #+#             */
/*   Updated: 2023/10/12 07:27:34 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
type [1] [-1]
*/
void	ft_rotate(t_game *game, int type, double rad)
{
	double	dir_x;
	double	dir_y;
	double	cam_x;
	double	cam_y;

	dir_x = game->dir.x;
	dir_y = game->dir.y;
	cam_x = game->cam.x;
	cam_y = game->cam.y;
	game->dir.x = dir_x * cos(rad) + (-type) * dir_y * sin(rad);
	game->dir.y = (type) * dir_x * sin(rad) + dir_y * cos(rad);
	game->cam.x = cam_x * cos(rad) + (-type) * cam_y * sin(rad);
	game->cam.y = (type) * cam_x * sin(rad) + cam_y * cos(rad);
	return ;
}

/*
2 * M_PI / (double) WIDTH calculates the angle increment 
per horizontal pixel on the screen,
which can be used to control how much the player's 
view rotates when moving the mouse horizontally.
*/
int	ft_mouse(int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	(void) y;
	mlx_mouse_hide(game->mlx, game->win);
	while (x > game->x++)
		ft_rotate(game, 1, 2 * M_PI / (double) WIDTH);
	while (x < game->x--)
		ft_rotate(game, -1, 2 * M_PI / (double) WIDTH);
	ft_draw(game);
	return (0);
}
