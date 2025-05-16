/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/13 09:58:06 by mona          #+#    #+#                 */
/*   Updated: 2025/05/16 18:23:08 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	char	**map;
	int		player_x;
	int		player_y;
	int		move_count;
}	t_game;

int	load_map(t_game *game, const char *path);
int	handle_key(int keycode, t_game *game);
void	free_map(char **map);

int	initialize_game(t_game *game);
int	has_collectibles(t_game *game);
void	render_map(t_game *game);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int	exit_game(t_game *game);


#endif