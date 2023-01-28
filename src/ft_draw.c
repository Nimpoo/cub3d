/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:24:37 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/26 22:27:29 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_set_pixel(t_cub3d *cub3d, t_vector v, unsigned int color)
{
	if (0 <= v.x && v.x < W_WIDTH && 0 <= v.y && v.y < W_HEIGHT)
		((unsigned int *) cub3d->frame.addr)[(int) v.y * W_WIDTH + (int) v.x]
			= color;
}

unsigned int	ft_get_pixel(t_image *img, t_vector v)
{
	if (v.x <= img->width && v.y < img->width
		&& v.y <= img->height && v.y < img->height)
		return (((unsigned int *) img->addr)[(int)(v.y * img->height + v.x)]);
	return (0);
}

double	ft_get_x_axis(t_cub3d *cub3d)
{
	double	x;

	if (cub3d->dda.side == 0 || cub3d->dda.side == 1)
		x = cub3d->player.position.y + cub3d->dda.perp_dist * cub3d->dda.ray.y;
	else
		x = cub3d->player.position.x + cub3d->dda.perp_dist * cub3d->dda.ray.x;
	x -= (int) x;
	if (cub3d->dda.side == 0 || cub3d->dda.side == 3)
		x = 1 - x;
	return (x);
}

void	ft_draw_line(t_cub3d *cub3d, int s, int e)
{
	int				i;
	const double	x = ft_get_x_axis(cub3d);
	t_image			*img;

	if (cub3d->dda.side == 0)
		img = &cub3d->textures.west;
	if (cub3d->dda.side == 1)
		img = &cub3d->textures.east;
	if (cub3d->dda.side == 2)
		img = &cub3d->textures.north;
	if (cub3d->dda.side == 3)
		img = &cub3d->textures.south;
	i = -1;
	while (++i < s)
		ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
			cub3d->textures.ceiling);
	i--;
	while (++i < e && i < W_HEIGHT)
		ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i}, ft_get_pixel(
				img, (t_vector){.x = round(x * (img->width - 1)), .y = round(
					((double) i - s) / (e - s) * (img->height - 1))}));
	i--;
	while (++i < W_HEIGHT)
		ft_set_pixel(cub3d, (t_vector){.x = cub3d->dda.x, .y = i},
			cub3d->textures.floor);
}
