/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_rgba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:32:50 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/16 02:35:29 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

int	ft_convert_rgba(int r, int g, int b, int a)
{
	if (0 > r || r > 255 || 0 > g || g > 255 || 0 > b || b > 255)
	{
		ft_put("Error\nColor out of range\n", 2);
		exit(9);
	}
	return (a << 24 | r << 16 | g << 8 | b);
}
