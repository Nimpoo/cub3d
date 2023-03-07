/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:27:04 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/26 22:27:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_vector(t_cub3d *cub3d, t_vector s, t_vector e, unsigned int c)
{
	t_vector	a;
	t_vector	dir;
	double		square;

	dir.x = e.x * 5;
	dir.y = e.y * -5;
	square = sqrt(dir.x * dir.x + dir.y * dir.y);
	a.x = dir.x / square;
	a.y = dir.y / square;
	while (((e.y >= 0 && dir.y <= 0) || (e.y < 0 && dir.y > 0))
		&& ((e.x >= 0 && dir.x >= 0) || (e.x < 0 && dir.x < 0)))
	{
		ft_set_pixel(cub3d, (t_vector)
		{.x = s.x * 5 + dir.x + 5, .y = s.y * 5 + -dir.y + 5}, c);
		dir.x -= a.x;
		dir.y -= a.y;
	}
}

void	ft_draw_map(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	l;
	int	k;

	i = -1;
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
		{
			l = -1;
			while (cub3d->map[i][j] == '1' && ++l < 5)
			{
				k = -1;
				while (++k < 5)
					ft_set_pixel(cub3d, (t_vector)
					{.x = j * 5 + l + 5, .y = i * 5 + k + 5}, 0xFFFFFF);
			}
		}
	}
	ft_draw_vector(cub3d, cub3d->player.position, cub3d->player.direction,
		0xFF00);
	ft_set_pixel(cub3d, (t_vector){.x = cub3d->player.position.x * 5 + 5, .y
		= cub3d->player.position.y * 5 + 5}, 0xFFFFFF);
}
