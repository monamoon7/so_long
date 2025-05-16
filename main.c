/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 15:51:01 by mona          #+#    #+#                 */
/*   Updated: 2025/05/16 14:52:25 by mona          ########   odam.nl         */
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
		free_map(game.map);
		return (1);
	}
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

