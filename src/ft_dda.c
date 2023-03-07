/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:22:32 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/26 22:26:41 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_set_line(t_cub3d *cub3d)
{
	const int	h = (int)(W_HEIGHT / cub3d->dda.perp_dist);
	const int	line_top = -h / 2 + W_HEIGHT / 2;
	const int	line_bottom = h / 2 + W_HEIGHT / 2;

	ft_draw_line(cub3d, line_top, line_bottom);
}

void	ft_perform_dda(t_cub3d *cub3d)
{
	cub3d->dda.map.x = cub3d->player.position.y;
	cub3d->dda.map.y = cub3d->player.position.x;
	while (cub3d->map[(int) cub3d->dda.map.x][(int) cub3d->dda.map.y] != '1')
	{
		if (cub3d->dda.side_dist.x < cub3d->dda.side_dist.y)
		{
			cub3d->dda.side_dist.x += cub3d->dda.delta.x;
			cub3d->dda.map.y += cub3d->dda.step.x;
			cub3d->dda.side = 0;
			if (cub3d->dda.step.x > 0)
				cub3d->dda.side = 1;
		}
		else
		{
			cub3d->dda.side_dist.y += cub3d->dda.delta.y;
			cub3d->dda.map.x += cub3d->dda.step.y;
			cub3d->dda.side = 2;
			if (cub3d->dda.step.y > 0)
				cub3d->dda.side = 3;
		}
	}
	cub3d->dda.perp_dist = cub3d->dda.side_dist.x - cub3d->dda.delta.x;
	if (cub3d->dda.side >= 2)
		cub3d->dda.perp_dist = cub3d->dda.side_dist.y - cub3d->dda.delta.y;
	ft_set_line(cub3d);
}

void	ft_calc_step(t_cub3d *cub3d)
{
	const t_vector	pos = cub3d->player.position;

	if (cub3d->dda.ray.x < 0)
	{
		cub3d->dda.step.x = -1;
		cub3d->dda.side_dist.x = (pos.x - (int) pos.x) * cub3d->dda.delta.x;
	}
	else
	{
		cub3d->dda.step.x = 1;
		cub3d->dda.side_dist.x = ((int) pos.x + 1 - pos.x) * cub3d->dda.delta.x;
	}
	if (cub3d->dda.ray.y < 0)
	{
		cub3d->dda.step.y = -1;
		cub3d->dda.side_dist.y = (pos.y - (int) pos.y) * cub3d->dda.delta.y;
	}
	else
	{
		cub3d->dda.step.y = 1;
		cub3d->dda.side_dist.y = ((int) pos.y + 1 - pos.y) * cub3d->dda.delta.y;
	}
	ft_perform_dda(cub3d);
}

void	ft_dda(t_cub3d *cub3d)
{
	double		xcam;

	cub3d->dda.x = -1;
	while (++cub3d->dda.x < W_WIDTH)
	{
		xcam = 2 * cub3d->dda.x / (double)W_WIDTH - 1;
		cub3d->dda.ray.x = cub3d->player.direction.x + cub3d->plane.x * xcam;
		cub3d->dda.ray.y = cub3d->player.direction.y + cub3d->plane.y * xcam;
		if (cub3d->dda.ray.x == 0)
			cub3d->dda.delta.x = 1e10;
		else
			cub3d->dda.delta.x = fabs(1 / cub3d->dda.ray.x);
		if (cub3d->dda.ray.y == 0)
			cub3d->dda.delta.y = 1e10;
		else
			cub3d->dda.delta.y = fabs(1 / cub3d->dda.ray.y);
		ft_calc_step(cub3d);
	}
}
