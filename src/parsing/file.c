/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:52:47 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/29 07:24:45 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_parse_file(t_cub3d *cub3d, char *filename)
{
	const int	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		ft_put3("Error\nunable to open \'", filename, "\'\n", 2);
		close(fd);
		exit(3);
	}
	ft_parse_textures(cub3d, fd);
	ft_parse_map(cub3d, fd);
	close(fd);
}
