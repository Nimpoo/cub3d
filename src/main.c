/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/14 12:39:39 by noalexan         ###   ########.fr       */
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

void	ft_key_handler(t_cub3d *cub3d)
{
	if (cub3d->keys & 0b1)
		if (cub3d->map[(int)(cub3d->player.position.y - 0.05)]
			[(int) cub3d->player.position.x] != '1')
			cub3d->player.position.y -= 0.05;
	if (cub3d->keys & 0b10)
		if (cub3d->map[(int) cub3d->player.position.y]
			[(int)(cub3d->player.position.x - 0.05)] != '1')
			cub3d->player.position.x -= 0.05;
	if (cub3d->keys & 0b100)
		if (cub3d->map[(int)(cub3d->player.position.y + 0.05)]
			[(int) cub3d->player.position.x] != '1')
			cub3d->player.position.y += 0.05;
	if (cub3d->keys & 0b1000)
		if (cub3d->map[(int) cub3d->player.position.y]
			[(int)(cub3d->player.position.x + 0.05)] != '1')
			cub3d->player.position.x += 0.05;
	if (cub3d->keys & 0b10000)
		ft_rotate_vector(&cub3d->player.direction, M_PI / 180 * 2);
	if (cub3d->keys & 0b100000)
		ft_rotate_vector(&cub3d->player.direction, M_PI / -180 * 2);
}

// perpendiculaire = new.x = point.y * -1, new.y = point.x

int	ft_keydown_handler(int key, t_cub3d *cub3d)
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

// (yb - ya) * (xc - xa) == (yc - ya) * (xb - xa)
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

void	ft_draw_walls(t_cub3d *cub3d)
{
	const t_vector	plane = {.x = 0, .y = cub3d->fov};
	t_vector		ray;
	int				x;
	double			camera_x;

	x = 0;
	camera_x = 2 * x / W_WIDTH - 1;
	ray.x = cub3d->player.direction.x + plane.x * camera_x;
	ray.y = cub3d->player.direction.y + plane.y * camera_x + 1;
	printf("ray x: %f\nray y: %f\n", ray.x, ray.y);
	ft_draw_direction(cub3d, cub3d->player.position, ray, 0xFF0000);
}

void	ft_loop(t_cub3d *cub3d)
{
	// mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->textures.background.img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->screen, 0, 0);
	ft_key_handler(cub3d);
	ft_draw_walls(cub3d);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->player.position.x * 10, cub3d->player.position.y * 10, 0xFFFFFF);
	ft_draw_map(cub3d);
	ft_draw_direction(cub3d, cub3d->player.position, cub3d->player.direction, 0x55FF55);
	ft_draw_direction(cub3d, (t_vector){.x = 2, .y = 20}, (t_vector){.x = 10, .y = 2}, 0xFF00);
	ft_draw_direction(cub3d, (t_vector){.x = 2, .y = 18}, (t_vector){.x = 10, .y = -2}, 0xFF);
	ft_draw_direction(cub3d, (t_vector){.x = 1, .y = 1}, (t_vector){.x = 1, .y = 0}, 0xFF00);
	ft_draw_direction(cub3d, (t_vector){.x = 1, .y = 1}, (t_vector){.x = 0, .y = -1}, 0xFF00);
	ft_draw_direction(cub3d, (t_vector){.x = 1, .y = 1}, (t_vector){.x = -1, .y = 0}, 0xFF00);
	ft_draw_direction(cub3d, (t_vector){.x = 1, .y = 1}, (t_vector){.x = 0, .y = 1}, 0xFF00);
	ft_draw_direction(cub3d, (t_vector){.x = 1, .y = 1}, (t_vector){.x = 0.71, .y = 0.71}, 0xFF00);
	printf("position x: %f\n", cub3d->player.position.x);
	printf("position y: %f\n", cub3d->player.position.y);
	printf("direction x: %f\n", cub3d->player.direction.x);
	printf("direction y: %f\n", cub3d->player.direction.y);
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
	cub3d->screen = mlx_new_image(cub3d->mlx, W_WIDTH, W_HEIGHT);
	cub3d->fov = .9;
	mlx_hook(cub3d->win, E_KEYPRESS, 0, ft_keydown_handler, cub3d);
	mlx_hook(cub3d->win, E_KEYRELEASE, 0, ft_keyrelease_handler, cub3d);
	mlx_hook(cub3d->win, E_QUIT, 0, (int (*)()) & exit, 0);
	mlx_loop_hook(cub3d->mlx, (int (*)()) & ft_loop, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
