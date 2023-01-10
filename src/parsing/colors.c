/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:28:48 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/10 18:17:49 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int	ft_cut_colors(char *rgb)
// {
// 	int	i;

// 	i = 0;
// 	while ()
// }

int	pars_colors(t_path *path, int b)
{
	int		color;
	char	**rgb;
	int		i;

	if (b)
		rgb = ft_split(path->floor, ',');
	else
		rgb = ft_split(path->ceiling, ',');
	i = 0;
	while (rgb[i])
	{
		color = atoi(rgb[i]);
		printf("rgb[i] = %s\n", rgb[i]);
		printf("\ncolor = %d\n\n", color);
		if (color < 0 || color > 255)
			return (error_bad_prefix(), 0);
		if (b)
			path->f[i] = color;
		else
			path->c[i] = color;
		printf("floor[i] = %d\n", path->f[i]);
		i++;
	}
	return (1);
}
