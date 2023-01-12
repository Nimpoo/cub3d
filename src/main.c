/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/12 11:19:56 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_loop(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->textures.background.img, 0, 0);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->textures.north.img,
		(W_WIDTH - cub3d->textures.north.width) / 2,
		(W_HEIGHT - cub3d->textures.north.height) / 2
		- cub3d->textures.north.height);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->textures.south.img,
		(W_WIDTH - cub3d->textures.south.width) / 2,
		(W_HEIGHT - cub3d->textures.south.height) / 2
		+ cub3d->textures.south.height);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->textures.east.img,
		(W_WIDTH - cub3d->textures.east.width) / 2 + cub3d->textures.east.width,
		(W_HEIGHT - cub3d->textures.east.height) / 2);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win,
		cub3d->textures.west.img,
		(W_WIDTH - cub3d->textures.west.width) / 2 - cub3d->textures.west.width,
		(W_HEIGHT - cub3d->textures.west.height) / 2);
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
	mlx_hook(cub3d->win, 17, 0, (int (*)()) & exit, 0);
	mlx_loop_hook(cub3d->mlx, (int (*)()) & ft_loop, cub3d);
	system("leaks cub3d");
	mlx_loop(cub3d->mlx);
	return (0);
}
