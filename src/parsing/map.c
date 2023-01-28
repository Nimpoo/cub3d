/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:54:20 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/28 09:36:58 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_add_line(char ***a, const char *line)
{
	int		i;
	char	**origin;

	i = 0;
	origin = NULL;
	if (*a)
	{
		while ((*a)[i])
			i++;
		origin = ft_calloc((i + 1) * sizeof(char *));
		i = -1;
		while ((*a)[++i])
			origin[i] = ft_strdup_and_free((*a)[i]);
		free(*a);
	}
	*a = ft_calloc((i + 2) * sizeof(char *));
	i = 0;
	if (origin)
	{
		while (origin[i] && ++i)
			(*a)[i - 1] = ft_strdup_and_free(origin[i - 1]);
		free(origin);
	}
	(*a)[i] = ft_strdup(line);
}

int	ft_is_not_a_valid_char(char **map, const int i, const int j)
{
	return (
		map[i][j] != '1'
		&& !ft_isspace(map[i][j])
		&& (
			map[i][j] == '0'
			|| map[i][j] == 'S'
			|| map[i][j] == 'N'
			|| map[i][j] == 'E'
			|| map[i][j] == 'W')
		&& (
			i == 0 || j == 0
			|| !map[i][j + 1]
			|| (map[i - 1] && (
				ft_strlen(map[i - 1]) <= j
				|| ft_isspace(map[i - 1][j])))
			|| (map[i + 1] && (
				ft_strlen(map[i + 1]) <= j
				|| ft_isspace(map[i + 1][j])))
			|| ft_isspace(map[i][j - 1])
			|| ft_isspace(map[i][j + 1]))
		);
}

void	ft_set_vector(t_cub3d *cub3d, const char c, const int i, const int j)
{
	cub3d->player.position = (t_vector){.x = j + .5, .y = i + .5};
	if (c == 'N')
	{
		cub3d->player.direction = (t_vector){.x = 0, .y = -1};
		cub3d->plane = (t_vector){.x = FOV, .y = 0};
	}
	else if (c == 'S')
	{
		cub3d->player.direction = (t_vector){.x = 0, .y = 1};
		cub3d->plane = (t_vector){.x = -FOV, .y = 0};
	}
	else if (c == 'E')
	{
		cub3d->player.direction = (t_vector){.x = 1, .y = 0};
		cub3d->plane = (t_vector){.x = 0, .y = FOV};
	}
	else if (c == 'W')
	{
		cub3d->player.direction = (t_vector){.x = -1, .y = 0};
		cub3d->plane = (t_vector){.x = 0, .y = -FOV};
	}
}

int	ft_is_a_valid_map(t_cub3d *cub3d, char **map)
{
	int	i;
	int	j;
	int	spawn;

	i = -1;
	spawn = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (spawn)
					return (0);
				spawn = 1;
				ft_set_vector(cub3d, map[i][j], i, j);
			}
			if (ft_is_not_a_valid_char(map, i, j))
				return (0);
		}
	}
	return (spawn);
}

void	ft_parse_map(t_cub3d *cub3d, const int fd)
{
	char	*line;
	int		nl;

	line = get_next_line(fd);
	nl = 0;
	while (line)
	{
		ft_add_line(&cub3d->map, line);
		if (*line)
			nl = 1;
		if (!*line && nl)
			(ft_put("Error\ninvalid map\n", 2), exit(11));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!ft_is_a_valid_map(cub3d, cub3d->map))
		(ft_put("Error\ninvalid map\n", 2), exit(11));
}
