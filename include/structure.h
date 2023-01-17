/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:22:01 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/17 05:24:01 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdlib.h>

typedef struct s_image
{
	void	*img;
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

typedef struct s_int_vector
{
	int	x;
	int	y;
}		t_int_vector;

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

typedef struct s_cub3d
{
	t_textures	textures;
	t_player	player;
	int8_t		keys;
	t_vector	plane;
	void		*frame;
	char		*frame_addr;
	char		**map;
	void		*mlx;
	void		*win;
}		t_cub3d;

#endif
