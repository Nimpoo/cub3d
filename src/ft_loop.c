/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:20:31 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/26 22:25:24 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_loop(t_cub3d *cub3d)
{
	ft_dda(cub3d);
	ft_key_handler(cub3d);
	ft_draw_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->frame.img, 0, 0);
}
