/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:09:54 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/17 05:54:18 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_move(t_cub3d *cub3d, t_vector v)
{
	if (cub3d->map[(int)(cub3d->player.position.y)]
		[(int)(cub3d->player.position.x + .9 * v.x)] != '1')
		cub3d->player.position.x += .035 * v.x;
	if (cub3d->map[(int)(cub3d->player.position.y - .9 * v.y)]
		[(int)(cub3d->player.position.x)] != '1')
		cub3d->player.position.y -= .035 * v.y;
}
