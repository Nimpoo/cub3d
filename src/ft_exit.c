/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:25:30 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/28 07:57:45 by noalexan         ###   ########.fr       */
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
	mlx_destroy_image(cub3d->mlx, cub3d->frame.img);
	i = -1;
	while (cub3d->map[++i])
		free(cub3d->map[i]);
	free(cub3d->map);
	// system("leaks cub3D");
	exit(0);
}
