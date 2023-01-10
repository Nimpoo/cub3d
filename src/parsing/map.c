/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:22:30 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/10 17:54:03 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_path(char *path)
{
	if (open(path, O_RDONLY) == -1)
		return (0);
	return (1);
}

int	ft_path(char *path)
{
	int	i;

	i = 0;
	while (!ft_isspace(path[i]))
		i++;
	while (ft_isspace(path[i]))
		i++;
	return (i);
}

void	ft_save_param(char *line, t_game *game)
{
	if (!ft_strncmp("NO ", line, 3))
		game->path.north = ft_strdup(line + ft_path(line));
	if (!ft_strncmp("SO ", line, 3))
		game->path.south = ft_strdup(line + ft_path(line));
	if (!ft_strncmp("WE ", line, 3))
		game->path.west = ft_strdup(line + ft_path(line));
	if (!ft_strncmp("EA ", line, 3))
		game->path.east = ft_strdup(line + ft_path(line));
	if (!ft_strncmp("C ", line, 2))
		game->path.ceiling = ft_strdup(line + ft_path(line));
	if (!ft_strncmp("F ", line, 2))
		game->path.floor = ft_strdup(line + ft_path(line));
}

int	ft_check_param(char *line, t_game *game)
{
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3)
		|| !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3)
		|| !ft_strncmp("C ", line, 2) || !ft_strncmp("F ", line, 2))
		return (ft_save_param(line, game), 1);
	return (0);
}

int	pars_map(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		nbr_config;

	line = get_next_line(fd);
	i = 0;
	nbr_config = 0;
	while (line[i] != '1')
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '\n' || !line[i])
			nbr_config--;
		else if (!ft_check_param(line + i, game))
			return (error_bad_prefix(), 0);
		nbr_config++;
		i = 0;
		line = get_next_line(fd);
	}
	if (nbr_config != 6)
		return (error_bad_prefix(), 0);
	if (!ft_check_path(game->path.north) || !ft_check_path(game->path.south)
		|| !ft_check_path(game->path.east) || !ft_check_path(game->path.west))
		return (error_bad_prefix(), 0);
	return (1);
}
