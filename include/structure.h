/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:22:01 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/23 07:21:30 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdlib.h>

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}		t_image;

typedef struct s_textures
{
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			west;
	unsigned int	ceiling;
	unsigned int	floor;
}		t_textures;

typedef struct s_vector
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
}		t_player;

typedef struct s_dda
{
	int			x;
	double		perp_dist;
	t_vector	ray;
	t_vector	delta;
	t_vector	step;
	t_vector	side_dist;
	t_vector	map;
	int			side;
}		t_dda;

typedef struct s_cub3d
{
	t_textures	textures;
	t_player	player;
	int8_t		keys;
	t_vector	plane;
	t_image		frame;
	t_dda		dda;
	char		**map;
	void		*mlx;
	void		*win;
}		t_cub3d;

#endif
