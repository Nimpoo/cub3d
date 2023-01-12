/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:56:48 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 11:32:29 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_set_image(t_cub3d *cub3d, t_image *img, char *path)
{
	if (ft_reverse_strncmp(path, ".xpm", 4))
	{
		ft_put3("Error\n'", path, "' not a XPM file\n", 2);
		exit(4);
	}
	img->img = mlx_xpm_file_to_image(
			cub3d->mlx,
			path,
			&img->width,
			&img->height);
	if (!img->img)
	{
		ft_put3("Error\nunable to open '", path, "'\n", 2);
		exit(5);
	}
}

void	ft_set_texture(t_cub3d *cub3d, const char *line)
{
	char	*path;

	if (*line)
	{
		path = ft_get_path(ft_skip_space(line + 2));
		if (!cub3d->textures.north.img && !ft_strncmp(line, "NO ", 3))
			ft_set_image(cub3d, &cub3d->textures.north, path);
		else if (!cub3d->textures.south.img && !ft_strncmp(line, "SO ", 3))
			ft_set_image(cub3d, &cub3d->textures.south, path);
		else if (!cub3d->textures.east.img && !ft_strncmp(line, "EA ", 3))
			ft_set_image(cub3d, &cub3d->textures.east, path);
		else if (!cub3d->textures.west.img && !ft_strncmp(line, "WE ", 3))
			ft_set_image(cub3d, &cub3d->textures.west, path);
		else
		{
			ft_put("Error\ninvalid map\n", 2);
			exit(6);
		}
		free(path);
	}
}

void	ft_parse_textures(t_cub3d *cub3d, const int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		ft_set_texture(cub3d, ft_skip_space(line));
		if (cub3d->textures.north.img && cub3d->textures.south.img
			&& cub3d->textures.east.img && cub3d->textures.west.img)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!cub3d->textures.north.img || !cub3d->textures.south.img
		|| !cub3d->textures.east.img || !cub3d->textures.west.img)
	{
		ft_put("Error\ninvalid map\n", 2);
		exit(7);
	}
}
