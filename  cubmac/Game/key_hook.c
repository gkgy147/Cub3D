/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:56:06 by grobert           #+#    #+#             */
/*   Updated: 2023/10/06 15:40:20 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_zoom(t_game *game)
{
	if (game->z == 1)
	{
		game->cam.x /= 8;
		game->cam.y /= 8;
		game->z = 8;
		ft_draw(game);
	}
	return ;
}

int	key_down(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keycode == 13)
		game->move_y = 1;
	else if (keycode == 1)
		game->move_y = -1;
	else if (keycode == 2)
		game->move_x = 1;
	else if (keycode == 0)
		game->move_x = -1;
	else if (keycode == 123)
		game->rotate = -1;
	else if (keycode == 124)
		game->rotate = 1;
	else if (keycode == 6)
		ft_zoom(game);
	else if (keycode == 53)
		ft_close(param);
	return (0);
}

int	key_up(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *) param;
	if (keycode == 13 || keycode == 1)
		game->move_y = 0;
	else if (keycode == 2 || keycode == 0)
		game->move_x = 0;
	else if (keycode == 123 || keycode == 124)
		game->rotate = 0;
	else if (keycode == 6 && game->z == 8)
	{
		game->cam.x *= 8;
		game->cam.y *= 8;
		game->z = 1;
	}
	return (0);
}

int	focus(void *param)
{
	t_game	*game;

	game = (t_game *) param;
	game->move_y = 0;
	game->move_x = 0;
	game->rotate = 0;
	if (game->z == 8)
	{
		game->cam.x *= 8;
		game->cam.y *= 8;
		game->z = 1;
	}
	return (0);
}
