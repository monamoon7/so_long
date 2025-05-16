/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.42.fr>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 15:51:01 by mona          #+#    #+#                 */
/*   Updated: 2025/05/16 18:57:19 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 28);
		return (1);
	}
	if (!load_map(&game, argv[1]))
	{
		write(2, "Failed to load map.\n", 21);
		return (1);
	}
	if (!initialize_game(&game))
	{	
		write(2, "Failed to initialize game.\n", 28);
		if (!game.img_wall)
			write(2, "Missing wall.xpm\n", 18);
		if (!game.img_floor)
			write(2, "Missing floor.xpm\n", 19);
		if (!game.img_player)
			write(2, "Missing player.xpm\n", 20);
		if (!game.img_coin)
			write(2, "Missing coin.xpm\n", 18);
		if (!game.img_exit)
			write(2, "Missing exit.xpm\n", 18);
		return (1);
	}
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
