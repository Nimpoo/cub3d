/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:48 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/11 15:50:00 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	pars_colors(t_path *path, int b)
{
	int		color;
	char	**rgb;
	int		i;

	i = 0;
	if (b)
		rgb = ft_split(path->floor, ',');
	else
		rgb = ft_split(path->ceiling, ',');
	while (rgb[i])
	{
		color = atoi(rgb[i]);
		// printf("rgb[i] = %s\n", rgb[i]);
		// printf("\ncolor = %d\n\n", color);
		if (color < 0 || color > 255)
			return (error_color(color, "Bad format ! Plz use [RGB] format"), 0);
		if (b)
			path->f[i] = color;
		else
			path->c[i] = color;
		// printf("floor[i] = %d\n", path->f[i]);
		i++;
	}
	return (1);
}
