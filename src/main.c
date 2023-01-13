/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/13 19:55:40 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_handler(t_cub3d *cub3d)
{
	if (cub3d->keys & 0b1)
		if (cub3d->map[(int)(cub3d->player.position.y - 0.2)][(int) cub3d->player.position.x] != '1')
			cub3d->player.position.y -= 0.2;
	if (cub3d->keys & 0b10)
		if (cub3d->map[(int) cub3d->player.position.y][(int)(cub3d->player.position.x - 0.2)] != '1')
			cub3d->player.position.x -= 0.2;
	if (cub3d->keys & 0b100)
		if (cub3d->map[(int)(cub3d->player.position.y + 0.2)][(int) cub3d->player.position.x] != '1')
			cub3d->player.position.y += 0.2;
	if (cub3d->keys & 0b1000)
		if (cub3d->map[(int) cub3d->player.position.y][(int)(cub3d->player.position.x + 0.2)] != '1')
			cub3d->player.position.x += 0.2;
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
void	ft_draw_direction(t_cub3d *cub3d)
{
	(void) cub3d;
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
		{
			if (cub3d->map[i][j] == '1')
			{
				for (int l = 0; l < 10; l++)
					for (int k = 0; k < 10; k++)
						mlx_pixel_put(cub3d->mlx, cub3d->win, j * 10 + l, i * 10 + k, 0xFF0000);
			}
		}
	}
	(void) cub3d;
}

void	ft_loop(t_cub3d *cub3d)
{
	// mlx_put_image_to_window(cub3d->mlx, cub3d->win,
	// 	cub3d->textures.background.img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->screen, 0, 0);
	ft_key_handler(cub3d);
	mlx_pixel_put(cub3d->mlx, cub3d->win, cub3d->player.position.x * 10, cub3d->player.position.y * 10, 0xFFFFFF);
	ft_draw_direction(cub3d);
	ft_draw_map(cub3d);
	printf("position x: %d\n", (int) cub3d->player.position.x);
	printf("position y: %d\n", (int) cub3d->player.position.y);
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
	mlx_hook(cub3d->win, E_KEYPRESS, 0, ft_keydown_handler, cub3d);
	mlx_hook(cub3d->win, E_KEYRELEASE, 0, ft_keyrelease_handler, cub3d);
	mlx_hook(cub3d->win, E_QUIT, 0, (int (*)()) & exit, 0);
	mlx_loop_hook(cub3d->mlx, (int (*)()) & ft_loop, cub3d);
	mlx_loop(cub3d->mlx);
	return (0);
}
