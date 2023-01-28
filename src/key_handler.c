/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:12:02 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/28 07:56:55 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_handler(t_cub3d *cub3d)
{
	if (cub3d->keys & 0b1)
		ft_move(cub3d, (t_vector){.x = cub3d->player.direction.x,
			.y = -cub3d->player.direction.y});
	if (cub3d->keys & 0b10)
		ft_move(cub3d, (t_vector){.x = cub3d->player.direction.y,
			.y = cub3d->player.direction.x});
	if (cub3d->keys & 0b100)
		ft_move(cub3d, (t_vector){.x = -cub3d->player.direction.x,
			.y = cub3d->player.direction.y});
	if (cub3d->keys & 0b1000)
		ft_move(cub3d, (t_vector){.x = -cub3d->player.direction.y,
			.y = -cub3d->player.direction.x});
	if (cub3d->keys & 0b10000)
	{
		ft_rotate_vector(&cub3d->player.direction, M_PI / 180 * -2);
		ft_rotate_vector(&cub3d->plane, M_PI / 180 * -2);
	}
	if (cub3d->keys & 0b100000)
	{
		ft_rotate_vector(&cub3d->player.direction, M_PI / -180 * -2);
		ft_rotate_vector(&cub3d->plane, M_PI / -180 * -2);
	}
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
		ft_exit(cub3d);
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
