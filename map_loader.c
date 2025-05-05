/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_loader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mona <mona@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/05 15:57:17 by mona          #+#    #+#                 */
/*   Updated: 2025/05/05 15:59:04 by mona          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_map_lines(const char *path)
{
	int		lines;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	close(fd);
	return (lines);
}

int	load_map(t_game *game, const char *path)
{
	int		fd;
	int		idx;
	int		rows;
	char	*line;

	rows = count_map_lines(path);
	if (rows <= 0)
		return (0);
	game->map = malloc((rows + 1) * sizeof(char *));
	if (!game->map)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	idx = 0;
	while ((line = get_next_line(fd)))
		game->map[idx++] = line;
	game->map[idx] = NULL;
	close(fd);
	return (1);
}
