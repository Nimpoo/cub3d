/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:09:54 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/29 14:16:30 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_move(t_cub3d *cub3d, t_vector v)
{
	char	c;

	c = cub3d->map[(int)(cub3d->player.position.y)]
	[(int)(cub3d->player.position.x + (SPEED + .05) * v.x)];
	if (c != '1' && !ft_isspace(c))
		cub3d->player.position.x += SPEED * v.x;
	c = cub3d->map[(int)(cub3d->player.position.y - (SPEED - .05) * v.y)]
	[(int)(cub3d->player.position.x)];
	if (c != '1' && !ft_isspace(c))
		cub3d->player.position.y -= SPEED * v.y;
}
