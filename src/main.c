/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/15 16:08:36 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rotate_vector(t_vector *v, double angle)
{
	double			x;
	double			y;

	x = cos(angle) * v->x + -sin(angle) * v->y;
	y = sin(angle) * v->x + cos(angle) * v->y;
	v->x = x;
	v->y = y;
}

void	ft_move(t_cub3d *cub3d, t_vector v)
{
	if (cub3d->map[(int)(cub3d->player.position.y)][(int)(cub3d->player.position.x + 0.05 * v.x)] != '1')
		cub3d->player.position.x += 0.05 * v.x;
	if (cub3d->map[(int)(cub3d->player.position.y + 0.05 * v.y)][(int)(cub3d->player.position.x)] != '1')
		cub3d->player.position.y += 0.05 * v.y;
}

void	ft_key_handler(t_cub3d *cub3d)
{
	if (cub3d->keys & 0b1)
		ft_move(cub3d, (t_vector){.x = cub3d->player.direction.x,
			.y = -cub3d->player.direction.y});
	if (cub3d->keys & 0b10)
		ft_move(cub3d, (t_vector){.x = -cub3d->player.direction.y,
			.y = -cub3d->player.direction.x});
	if (cub3d->keys & 0b100)
		ft_move(cub3d, (t_vector){.x = -cub3d->player.direction.x,
			.y = cub3d->player.direction.y});
	if (cub3d->keys & 0b1000)
		ft_move(cub3d, (t_vector){.x = cub3d->player.direction.y,
			.y = cub3d->player.direction.x});
	if (cub3d->keys & 0b10000)
	{
		ft_rotate_vector(&cub3d->player.direction, M_PI / 180 * 2);
		ft_rotate_vector(&cub3d->plane, M_PI / 180 * 2);
	}
	if (cub3d->keys & 0b100000)
	{
		ft_rotate_vector(&cub3d->player.direction, M_PI / -180 * 2);
		ft_rotate_vector(&cub3d->plane, M_PI / -180 * 2);
	}
}

// perpendiculaire = new.x = point.y * -1, new.y = point.x

void	ft_exit(t_cub3d *cub3d)
{
	int	i;

	mlx_destroy_window(cub3d->mlx, cub3d->win);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.north.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.south.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.east.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.west.img);
	mlx_destroy_image(cub3d->mlx, cub3d->textures.background.img);
	i = -1;
	while (cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
	exit(0);
}

int	ft_keypress_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->keys = cub3d->keys | 0b1;
	else if (key == KEY_A)
		cub3d->keys = cub3d->keys | 0b10;
	else if (key == KEY_S)
		cub3d->keys = cub3d->keys | 0b100;
	else if (key == KEY_D)
		cub3d->keys = cub3d->keys | 0b1000;
	else if (key == KEY_ARROW_LEFT)
		cub3d->keys = cub3d->keys | 0b10000;
	else if (key == KEY_ARROW_RIGHT)
		cub3d->keys = cub3d->keys | 0b100000;
	else if (key == KEY_ESC)
		exit(0);
	else
		printf("unknown key: %d\n", key);
	return (0);
}

int	ft_keyrelease_handler(int key, t_cub3d *cub3d)
{
	if (key == KEY_W)
		cub3d->keys = cub3d->keys & ~0b1;
	else if (key == KEY_A)
		cub3d->keys = cub3d->keys & ~0b10;
	else if (key == KEY_S)
		cub3d->keys = cub3d->keys & ~0b100;
	else if (key == KEY_D)
		cub3d->keys = cub3d->keys & ~0b1000;
	else if (key == KEY_ARROW_LEFT)
		cub3d->keys = cub3d->keys & ~0b10000;
	else if (key == KEY_ARROW_RIGHT)
		cub3d->keys = cub3d->keys & ~0b100000;
	return (0);
}

void	ft_draw_direction(t_cub3d *cub3d, t_vector start, t_vector end, unsigned int color)
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;

	dir_x = end.x * 10;
	dir_y = end.y * -10;
	x = dir_x / 100;
	y = dir_y / 100;
	while (((end.y >= 0 && dir_y <= 0) || (end.y < 0 && dir_y > 0)) && ((end.x >= 0 && dir_x >= 0) || (end.x < 0 && dir_x < 0)))
	{
		mlx_pixel_put(cub3d->mlx, cub3d->win, (int)(start.x * 10 + dir_x), (int)(start.y * 10 + dir_y), color);
		dir_x -= x;
		dir_y -= y;
	}
}

void	ft_draw_map(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (cub3d->map[++i])
	{
		j = -1;
		while (cub3d->map[i][++j])
			if (cub3d->map[i][j] == '1')
				for (int l = 0; l < 10; l++)
					for (int k = 0; k < 10; k++)
						mlx_pixel_put(cub3d->mlx, cub3d->win, j * 10 + l, i * 10 + k, 0x9AFF0000);
	}
}

// void	ft_draw_line(t_cub3d *cub3d, int x, int start, int end, unsigned int color)
// {
// 	while (start < end)
// 	{
// 		mlx_pixel_put(cub3d->mlx, cub3d->win, x, start, color);
// 		start++;
// 	}
// }

void	ft_draw_walls(t_cub3d *cub3d)
{
	t_vector	ray;
	double		camera_x;
	int			x;

	x = 0;
	while (x <= W_WIDTH)
	{
		camera_x = 2 * x / (double) W_WIDTH - 1;
		ray.x = cub3d->player.direction.x + cub3d->plane.x * camera_x;
		ray.y = cub3d->player.direction.y + cub3d->plane.y * camera_x;
		if (!(x % 400))
// 		{
// 			int mapX = (int) cub3d->player.position.x;
// 			int mapY = (int) cub3d->player.position.y;

// 			int stepX;
// 			int stepY;

// 			double sideDistX;
// 			double sideDistY;

			ft_draw_direction(cub3d, cub3d->player.position, (t_vector){.x = ray.x * 20, .y = ray.y * 20}, 0xFF0000);

// 			double deltaDistX = sqrt(1 + (ray.y * ray.y) / (ray.x * ray.x));
// 			double deltaDistY = sqrt(1 + (ray.x * ray.x) / (ray.y * ray.y));

// 			if (ray.x < 0)
// 			{
// 				stepX = -1;
// 				sideDistX = (cub3d->player.position.x - mapX) * deltaDistX;
// 			}
// 			else
// 			{
// 				stepX = 1;
// 				sideDistX = (mapX + 1.0 - cub3d->player.position.x) * deltaDistX;
// 			}
// 			if (ray.y < 0)
// 			{
// 				stepY = -1;
// 				sideDistY = (cub3d->player.position.y - mapY) * deltaDistY;
// 			}
// 			else
// 			{
// 				stepY = 1;
// 				sideDistY = (mapY + 1.0 - cub3d->player.position.y) * deltaDistY;
// 			}

// 			int hit = 0;
// 			int side;

// 			while (hit == 0)
// 			{
// 				if (sideDistX < sideDistY)
// 				{
// 					sideDistX += deltaDistX;
// 					mapX += stepX;
// 					side = 0;
// 				}
// 				else
// 				{
// 					sideDistY += deltaDistY;
// 					mapY += stepY;
// 					side = 1;
// 				}
// 				if (cub3d->map[mapY][mapX] > 0) hit = 1;
// 			}

// 			double perpWallDist;
// 			if(side == 0)
// 				perpWallDist = (sideDistX - deltaDistX);
// 			else
// 				perpWallDist = (sideDistY - deltaDistY);

// 			int lineHeight = (int) (W_HEIGHT / perpWallDist);

// 			int drawStart = -lineHeight / 2 + W_HEIGHT / 2;
// 			if(drawStart < 0) drawStart = 0;
// 			int drawEnd = lineHeight / 2 + W_HEIGHT / 2;
// 			if(drawEnd >= W_HEIGHT) drawEnd = W_HEIGHT - 1;

// 			unsigned int color = 0xFF;
// 			if (side == 1) color = color / 2;

// 			ft_draw_line(cub3d, x, drawStart, drawEnd, color);

// 		}
		x++;
	}
}

void	ft_loop(t_cub3d *cub3d)
{
	ft_key_handler(cub3d);
	ft_draw_map(cub3d);
	ft_draw_walls(cub3d);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->player.position.x * 10, cub3d->player.position.y * 10, 0xFFFFFF);
	mlx_clear_window(cub3d->mlx, cub3d->win);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	if (argc != 2)
	{
		ft_put("Error\nbad arguments\n", 2);
		exit(1);
	}
	if (ft_reverse_strncmp(argv[1], ".cub", 4))
	{
		ft_put3("Error\n'", argv[1], "' not a CUB file\n", 2);
		exit(2);
	}
	cub3d = ft_calloc(sizeof(t_cub3d));
	cub3d->mlx = mlx_init();
	ft_parse_file(cub3d, argv[1]);
	cub3d->win = mlx_new_window(cub3d->mlx, W_WIDTH, W_HEIGHT, "cub3d");
	mlx_hook(cub3d->win, E_KEYPRESS, 0, ft_keypress_handler, cub3d);
	mlx_hook(cub3d->win, E_KEYRELEASE, 0, ft_keyrelease_handler, cub3d);
	mlx_hook(cub3d->win, E_QUIT, 0, (int (*)()) & exit, 0);
	mlx_loop_hook(cub3d->mlx, (int (*)()) & ft_loop, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
