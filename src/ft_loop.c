/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:20:31 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/21 06:37:04 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_exit(t_cub3d *cub3d)
{
	int	i;

	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.north.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.south.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.east.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.west.img);
	i = -1;
	while (cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
	exit(0);
}

void	ft_set_pixel(t_cub3d *cub3d, t_vector v, unsigned int color)
{
	if (0 <= v.x && v.x < W_WIDTH && 0 <= v.y && v.y < W_HEIGHT)
		((unsigned int *) cub3d->frame.addr)[(int) v.y * W_WIDTH + (int) v.x]
			= color;
}

unsigned int	ft_get_pixel(t_image *img, t_vector v)
{
	if (v.x <= img->width && v.y < img->width
		&& v.y <= img->height && v.y < img->height)
		return (((unsigned int *) img->addr)[(int)(v.y * img->height + v.x)]);
	return (0);
}

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

void	ft_draw_line(t_cub3d *cub3d, int start, int end)
{
	int		i;
	t_image	*img;

	if (cub3d->dda.side == 0)
		img = &cub3d->textures.west;
	if (cub3d->dda.side == 1)
		img = &cub3d->textures.east;
	if (cub3d->dda.side == 2)
		img = &cub3d->textures.north;
	if (cub3d->dda.side == 3)
		img = &cub3d->textures.south;
	i = -1;
	while (++i < start)
		ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
			cub3d->textures.ceiling);
	i--;
	if (cub3d->dda.x == W_WIDTH / 2)
	{
		printf("%f\n", (cub3d->dda.map.y - (int) cub3d->dda.map.y) * img->width);
		// exit(0);
	}
	while (++i < end && i < W_HEIGHT)
	{
		if (cub3d->dda.side == 0 || cub3d->dda.side == 1)
			ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
				ft_get_pixel(img, (t_vector){.x = 0 /* (cub3d->dda.map.x - (int) cub3d->dda.map.x) * img->width */, .y = (i - start) / (end - start) * img->height}));
		else if (cub3d->dda.side == 2 || cub3d->dda.side == 3)
			ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
				ft_get_pixel(img, (t_vector){.x = 0 /* (cub3d->dda.map.y - (int) cub3d->dda.map.y) * img->width */, .y = (i - start) / (end - start) * img->height}));
	}
	i--;
	while (++i < W_HEIGHT)
		ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
			cub3d->textures.floor);
}

void	ft_set_line(t_cub3d *cub3d, double perpendicular_dist)
{
	const int	h = (int)(W_HEIGHT / perpendicular_dist);
	const int	line_top = -h / 2 + W_HEIGHT / 2;
	const int	line_bottom = h / 2 + W_HEIGHT / 2;

	ft_draw_line(cub3d, line_top, line_bottom);
}

void	ft_perform_dda(t_cub3d *cub3d)
{
	cub3d->dda.map.x = cub3d->player.position.y;
	cub3d->dda.map.y = cub3d->player.position.x;
	while (cub3d->map[(int) cub3d->dda.map.x][(int) cub3d->dda.map.y] != '1')
	{
		if (cub3d->dda.side_dist.x < cub3d->dda.side_dist.y)
		{
			cub3d->dda.side_dist.x += cub3d->dda.delta.x;
			cub3d->dda.map.y += cub3d->dda.step.x;
			cub3d->dda.side = 0;
			if (cub3d->dda.step.x > 0)
				cub3d->dda.side++;
		}
		else
		{
			cub3d->dda.side_dist.y += cub3d->dda.delta.y;
			cub3d->dda.map.x += cub3d->dda.step.y;
			cub3d->dda.side = 2;
			if (cub3d->dda.step.y > 0)
				cub3d->dda.side++;
		}
	}
	if (cub3d->dda.side >= 2)
		ft_set_line(cub3d, cub3d->dda.side_dist.y - cub3d->dda.delta.y);
	else
		ft_set_line(cub3d, cub3d->dda.side_dist.x - cub3d->dda.delta.x);
}

void	ft_calc_step(t_cub3d *cub3d)
{
	const t_vector	pos = cub3d->player.position;

	if (cub3d->dda.ray.x < 0)
	{
		cub3d->dda.step.x = -1;
		cub3d->dda.side_dist.x = (pos.x - (int) pos.x) * cub3d->dda.delta.x;
	}
	else
	{
		cub3d->dda.step.x = 1;
		cub3d->dda.side_dist.x = ((int) pos.x + 1 - pos.x) * cub3d->dda.delta.x;
	}
	if (cub3d->dda.ray.y < 0)
	{
		cub3d->dda.step.y = -1;
		cub3d->dda.side_dist.y = (pos.y - (int) pos.y) * cub3d->dda.delta.y;
	}
	else
	{
		cub3d->dda.step.y = 1;
		cub3d->dda.side_dist.y = ((int) pos.y + 1 - pos.y) * cub3d->dda.delta.y;
	}
	ft_perform_dda(cub3d);
}

void	ft_dda(t_cub3d *cub3d)
{
	double		xcam;

	cub3d->dda.x = -1;
	while (++cub3d->dda.x < W_WIDTH)
	{
		xcam = 2 * cub3d->dda.x / (double)W_WIDTH - 1;
		cub3d->dda.ray.x = cub3d->player.direction.x + cub3d->plane.x * xcam;
		cub3d->dda.ray.y = cub3d->player.direction.y + cub3d->plane.y * xcam;
		if (cub3d->dda.ray.x == 0)
			cub3d->dda.delta.x = 1e10;
		else
			cub3d->dda.delta.x = fabs(1 / cub3d->dda.ray.x);
		if (cub3d->dda.ray.y == 0)
			cub3d->dda.delta.y = 1e10;
		else
			cub3d->dda.delta.y = fabs(1 / cub3d->dda.ray.y);
		ft_calc_step(cub3d);
	}
}

void	ft_loop(t_cub3d *cub3d)
{
	ft_dda(cub3d);
	ft_key_handler(cub3d);
	ft_draw_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->frame.img, 0, 0);
}
