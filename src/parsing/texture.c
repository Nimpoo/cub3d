/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:56:48 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/29 15:08:26 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_set_image(t_cub3d *cub3d, t_image *img, const char *s)
{
	const char	*path = ft_skip_space(s);
	int			i;

	if (ft_reverse_strncmp(path, ".xpm", 4))
	{
		ft_put3("Error\n'", path, "' not a XPM file\n", 2);
		exit(4);
	}
	img->img = mlx_xpm_file_to_image(
			cub3d->mlx,
			(char *) path,
			&img->width,
			&img->height);
	if (!img->img)
	{
		ft_put3("Error\nunable to open '", path, "'\n", 2);
		exit(5);
	}
	img->addr = mlx_get_data_addr(img->img, &i, &i, &i);
}

void	ft_set_color(unsigned int *f, unsigned int *c, const char *line)
{
	char	*_rgb;
	char	**rgb;

	if ((*line == 'C' && *c == 0xFFFFFF1) || (*line == 'F' && *f == 0xFFFFFF1))
	{
		_rgb = ft_strdup(line + 1);
		free(malloc(!printf("") + 64));
		rgb = ft_split(_rgb, ',');
		if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
			(ft_put("Error\ninvalid map\n", 2), exit(8));
		if (!ft_strncmp(line, "F ", 2))
			*f = ft_convert_rgba(ft_atoi(rgb[0]),
					ft_atoi(rgb[1]), ft_atoi(rgb[2]), 0);
		else if (!ft_strncmp(line, "C ", 2))
			*c = ft_convert_rgba(ft_atoi(rgb[0]),
					ft_atoi(rgb[1]), ft_atoi(rgb[2]), 0);
		(free(rgb[0]), free(rgb[1]), free(rgb[2]), free(rgb), free(_rgb));
	}
	else if (*line)
		(ft_put("Error\ninvalid map\n", 2), exit(9));
}

void	ft_set_texture(t_cub3d *cub3d, const char *line)
{
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
	{
		if (!cub3d->textures.north.img && !ft_strncmp(line, "NO ", 3))
			ft_set_image(cub3d, &cub3d->textures.north, line + 2);
		else if (!cub3d->textures.south.img && !ft_strncmp(line, "SO ", 3))
			ft_set_image(cub3d, &cub3d->textures.south, line + 2);
		else if (!cub3d->textures.east.img && !ft_strncmp(line, "EA ", 3))
			ft_set_image(cub3d, &cub3d->textures.east, line + 2);
		else if (!cub3d->textures.west.img && !ft_strncmp(line, "WE ", 3))
			ft_set_image(cub3d, &cub3d->textures.west, line + 2);
		else
			(ft_put("Error\ninvalid map\n", 2), exit(6));
		printf("line SO : %s\n", line);
	}
	else
		ft_set_color(&cub3d->textures.floor, &cub3d->textures.ceiling,
			ft_skip_space(line));
}

void	ft_parse_textures(t_cub3d *cub3d, const int fd)
{
	char	*line;

	line = get_next_line(fd);
	cub3d->textures.floor = 0xFFFFFF1;
	cub3d->textures.ceiling = 0xFFFFFF1;
	while (line)
	{
		ft_set_texture(cub3d, ft_skip_space(line));
		if (cub3d->textures.north.img && cub3d->textures.south.img
			&& cub3d->textures.east.img && cub3d->textures.west.img
			&& cub3d->textures.floor != 0xFFFFFF1
			&& cub3d->textures.ceiling != 0xFFFFFF1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!cub3d->textures.north.img || !cub3d->textures.south.img
		|| !cub3d->textures.east.img || !cub3d->textures.west.img)
		(ft_put("Error\ninvalid map\n", 2), exit(7));
	if (cub3d->textures.floor == 0xFFFFFF1
		|| cub3d->textures.ceiling == 0xFFFFFF1)
		(ft_put("Error\ninvalid map\n", 2), exit(10));
}
