/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 16:00:40 by mona          #+#    #+#                 */
/*   Updated: 2025/05/05 17:07:15 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_game(t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, 640, 480, "so_long");
	if (!game->win)
		return (0);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &w, &h);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "assets/coin.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &w, &h);
	return (1);
}