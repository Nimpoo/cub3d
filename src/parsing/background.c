/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:55:30 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/27 09:15:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

	line = get_next_line(fd);
	while (line)
	{
		ft_set_color(&cub3d->textures.floor, &cub3d->textures.ceiling,
			ft_skip_space(line));
		if (cub3d->textures.floor && cub3d->textures.ceiling)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (!cub3d->textures.floor || !cub3d->textures.ceiling)
	{
		ft_put("Error\ninvalid map\n", 2);
		exit(10);
	}
}
