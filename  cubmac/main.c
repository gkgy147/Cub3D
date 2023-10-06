/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:08:41 by grobert           #+#    #+#             */
/*   Updated: 2023/10/06 15:47:07 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(t_game *game)
{
	mlx_hook(game->win, 10, 0, focus, game);
	mlx_hook(game->win, 2, 0, key_down, game);
	mlx_hook(game->win, 3, 0, key_up, game);
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_hook(game->win, 6, 0, ft_mouse, game);
}

int	ft_game(void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (game->move_x || game->move_y)
		ft_move(game);
	if (game->rotate)
		ft_rotate(game, game->rotate, M_PI / 2.0f / game->fps);
	ft_draw(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_error("arguments", 1));
	game.pars.path = av[1];
	ft_init(&game);
	game.mlx = mlx_init();
	if (ft_parser(&game))
	{
		ft_die(&game);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Cub3D");
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.addr = mlx_get_data_address(game.img, &game.bpp,
			&game.ll, &game.endian);
	ft_draw(&game);
	mlx_do_sync(game.mlx);
	ft_hook(&game);
	mlx_loop_hook(game.mlx, ft_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
