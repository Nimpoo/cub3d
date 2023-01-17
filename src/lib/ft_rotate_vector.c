/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:08:02 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/17 05:04:14 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_rotate_vector(t_vector *v, double angle)
{
	double	x;
	double	y;

	x = cos(angle) * v->x + -sin(angle) * v->y;
	y = sin(angle) * v->x + cos(angle) * v->y;
	v->x = x;
	v->y = y;
}
