/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:55:30 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/13 14:27:38 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_convert_rgba(int r, int g, int b, int a)
{
	if (0 > r || r > 255 || 0 > g || g > 255 || 0 > b || b > 255)
	{
		ft_put("Error\nColor out of range\n", 2);
		exit(9);
	}
	return (a << 24 | r << 16 | g << 8 | b);
}

void	ft_set_background(t_cub3d *cub3d, unsigned int f, unsigned int c)
{
	int		i;
	char	*addr;

	cub3d->textures.background.width = W_WIDTH;
	cub3d->textures.background.height = W_HEIGHT;
	cub3d->textures.background.img
		= mlx_new_image(cub3d->mlx, W_WIDTH, W_HEIGHT);
	addr = mlx_get_data_addr(cub3d->textures.background.img, &i, &i, &i);
	i = -1;
	while (i < W_WIDTH * (W_HEIGHT / 2))
	{
		((unsigned int *) addr)[i] = c;
		i++;
	}
	while (i < W_WIDTH * W_HEIGHT)
	{
		((unsigned int *) addr)[i] = f;
		i++;
	}
}

void	ft_set_color(unsigned int *f, unsigned int *c, const char *line)
{
	char	*_rgb;
	char	**rgb;

	if (*line)
	{
		_rgb = ft_strdup(line + 1);
		rgb = ft_split(_rgb, ',');
		if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		{
			ft_put("Error\ninvalid map\n", 2);
			exit(8);
		}
		if (!*f && !ft_strncmp(line, "F ", 2))
			*f = ft_convert_rgba(ft_atoi(ft_skip_space(rgb[0])),
					ft_atoi(ft_skip_space(rgb[1])),
					ft_atoi(ft_skip_space(rgb[2])), 0);
		else if (!*c && !ft_strncmp(line, "C ", 2))
			*c = ft_convert_rgba(ft_atoi(ft_skip_space(rgb[0])),
					ft_atoi(ft_skip_space(rgb[1])),
					ft_atoi(ft_skip_space(rgb[2])), 0);
		(free(rgb[0]), free(rgb[1]), free(rgb[2]), free(rgb), free(_rgb));
	}
}

void	ft_parse_colors(t_cub3d *cub3d, const int fd)
{
	char			*line;
	unsigned int	floor;
	unsigned int	ceiling;

	line = get_next_line(fd);
	floor = 0;
	ceiling = 0;
	while (line)
	{
		ft_set_color(&floor, &ceiling, ft_skip_space(line));
		if (floor && ceiling)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!floor || !ceiling)
	{
		ft_put("Error\ninvalid map\n", 2);
		exit(10);
	}
	ft_set_background(cub3d, floor, ceiling);
}
