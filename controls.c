/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 12:21:38 by mona          #+#    #+#                 */
/*   Updated: 2025/05/16 14:44:01 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_move_count(int count)
{
	ft_putstr("Move: ");
	ft_putnbr(count);
	ft_putstr("\n");
}

static void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	tile = game->map[new_y][new_x];
	if (tile == '1')
		return ;
	if (tile == 'E' && has_collectibles(game))
		return ;
	if (tile == 'C')
		game->map[new_y][new_x] = '0';
	if (tile == 'E')
	{
		game->move_count++;
		ft_putstr("You win in ");
		ft_putnbr(game->move_count);
		ft_putstr(" moves!\n");
		exit_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	print_move_count(game->move_count);
	render_map(game);
}
