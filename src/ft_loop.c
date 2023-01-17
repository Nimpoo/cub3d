/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:20:31 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/17 07:31:16 by noalexan         ###   ########.fr       */
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
		((unsigned int *)cub3d->frame_addr)[(int)v.y * W_WIDTH + (int)v.x]
			= color;
}

void	ft_draw_vector(t_cub3d *cub3d, t_vector s, t_vector e, unsigned int c)
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;

	dir_x = e.x * 5;
	dir_y = e.y * -5;
	x = dir_x / 100;
	y = dir_y / 100;
	while (((e.y >= 0 && dir_y <= 0) || (e.y < 0 && dir_y > 0))
		&& ((e.x >= 0 && dir_x >= 0) || (e.x < 0 && dir_x < 0)))
	{
		ft_set_pixel(cub3d, (t_vector)
		{.x = s.x * 5 + dir_x + 5, .y = s.y * 5 + -dir_y + 5}, c);
		dir_x -= x;
		dir_y -= y;
	}
}

void ft_draw_map(t_cub3d *cub3d)
{
	int i;
	int j;

	i = -1;
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
			if (cub3d->map[i][j] == '1')
				for (int l = 0; l < 5; l++)
					for (int k = 0; k < 5; k++)
						ft_set_pixel(cub3d, (t_vector){.x = j * 5 + l + 5, .y = i * 5 + k + 5}, ft_convert_rgba(255, 255, 255, 100));
	}
	ft_draw_vector(cub3d, cub3d->player.position, cub3d->player.direction, 0xFF00);
	ft_set_pixel(cub3d, (t_vector){.x = cub3d->player.position.x * 5 + 5, .y = cub3d->player.position.y * 5 + 5}, 0xFFFFFF);
}

void ft_draw_line(t_cub3d *cub3d, int x, int start, int end, unsigned int color)
{
	int i;

	i = -1;
	while (++i < start)
		ft_set_pixel(cub3d, (t_vector){.x = x, .y = i}, cub3d->textures.ceiling);
	i--;
	while (++i < end)
		ft_set_pixel(cub3d, (t_vector){.x = x, .y = i}, color);
	i--;
	while (++i < W_HEIGHT)
		ft_set_pixel(cub3d, (t_vector){.x = x, .y = i}, cub3d->textures.floor);
}

void ft_set_line(t_cub3d *cub3d, int x, double perpendicular_dist, int side)
{
	const int h = (int)(W_HEIGHT / perpendicular_dist);
	const int line_top = -h / 2 + W_HEIGHT / 2;
	const int line_bottom = h / 2 + W_HEIGHT / 2;
	const unsigned int color = 0x313131 / (side + 1);

	ft_draw_line(cub3d, x, line_top, line_bottom, color);
}

void ft_perform_dda(t_cub3d *cub3d, t_vector *vectors, int x)
{
	int map_y;
	int map_x;
	int side;

	map_y = (int)cub3d->player.position.x;
	map_x = (int)cub3d->player.position.y;
	while (cub3d->map[map_x][map_y] != '1')
	{
		if (vectors[1].x < vectors[1].y)
		{
			vectors[1].x += vectors[0].x;
			map_y += vectors[2].x;
			side = 0;
		}
		else
		{
			vectors[1].y += vectors[0].y;
			map_x += vectors[2].y;
			side = 1;
		}
	}
	if (side)
		ft_set_line(cub3d, x, vectors[1].y - vectors[0].y, side);
	else
		ft_set_line(cub3d, x, vectors[1].x - vectors[0].x, side);
}

void ft_calc_step(t_cub3d *cub3d, t_vector ray, t_vector delta, int x)
{
	const t_vector pos = cub3d->player.position;
	t_vector step;
	t_vector side_dist;

	if (ray.x < 0)
	{
		step.x = -1;
		side_dist.x = (pos.x - (int)pos.x) * delta.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = ((int)pos.x + 1. - pos.x) * delta.x;
	}
	if (ray.y < 0)
	{
		step.y = -1;
		side_dist.y = (pos.y - (int)pos.y) * delta.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = ((int)pos.y + 1. - pos.y) * delta.y;
	}
	ft_perform_dda(cub3d, (t_vector[]){delta, side_dist, step}, x);
}

void ft_dda(t_cub3d *cub3d)
{
	t_vector ray;
	t_vector delta;
	int x;
	double camera_x;

	x = -1;
	while (++x < W_WIDTH)
	{
		camera_x = 2 * x / (double)W_WIDTH - 1;
		ray.x = cub3d->player.direction.x + cub3d->plane.x * camera_x;
		ray.y = cub3d->player.direction.y + cub3d->plane.y * camera_x;
		if (ray.x == 0)
			delta.x = 1e10;
		else
			delta.x = fabs(1 / ray.x);
		if (ray.y == 0)
			delta.y = 1e10;
		else
			delta.y = fabs(1 / ray.y);
		ft_calc_step(cub3d, ray, delta, x);
	}
}

void ft_clear_frame(t_cub3d *cub3d)
{
	int i;

	i = -1;
	while (++i <= W_HEIGHT * W_WIDTH)
		((unsigned int *)cub3d->frame_addr)[i] = 0x0F423F;
}

void ft_loop(t_cub3d *cub3d)
{
	ft_key_handler(cub3d);
	ft_dda(cub3d);
	ft_draw_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->frame, 0, 0);
}
