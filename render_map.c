/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 16:21:50 by mona          #+#    #+#                 */
/*   Updated: 2025/05/05 16:54:26 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;
	char	tile;
	void	*img;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			tile = game->map[y][x];
			if (tile == '1')
				img = game->img_wall;
			else if (tile == '0')
				img = game->img_floor;
			else if (tile == 'P')
				img = game->img_player;
			else if (tile == 'C')
				img = game->img_coin;
			else if (tile == 'E')
				img = game->img_exit;
			else
				img = game->img_floor;
			mlx_put_image_to_window(game->mlx, game->win,
				img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
