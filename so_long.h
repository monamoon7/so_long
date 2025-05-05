/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/13 09:58:06 by mona          #+#    #+#                 */
/*   Updated: 2025/05/05 16:01:10 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <get_next_line.h>

# define TITLE_SIZE 64

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
}	t_game;

int	load_map(t_game *game, const char *path);

int	initialize_game(t_game *game);

#endif