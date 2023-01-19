/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:09:54 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/18 06:04:25 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move(t_cub3d *cub3d, t_vector v)
{
	if (cub3d->map[(int)(cub3d->player.position.y)]
		[(int)(cub3d->player.position.x + .2 * v.x)] != '1')
		cub3d->player.position.x += .04 * v.x;
	if (cub3d->map[(int)(cub3d->player.position.y - .2 * v.y)]
		[(int)(cub3d->player.position.x)] != '1')
		cub3d->player.position.y -= .04 * v.y;
}
