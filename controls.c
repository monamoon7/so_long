/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/16 12:21:38 by mona          #+#    #+#                 */
/*   Updated: 2025/05/16 12:34:03 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int new_y = game->player_y + dy;
	char	next_tile = game->map[new_y][new_x];
	
	if (next_tile = '1')
		return;
	if (next_tile = 'E' && has_collectibles(game))
		return;
	if (next_tile == 'C')
		game->map[new_y][new_x] = '0';
	if (next_tile == 'E')
	{
		
	}
}