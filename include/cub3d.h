/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:20:46 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 12:34:47 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include "../minilibx/mlx.h"
# include "lib.h"

# define W_WIDTH 800
# define W_HEIGHT 500

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}		t_image;

typedef struct s_textures
{
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	t_image	background;
}		t_textures;

typedef struct s_player
{
	double	x;
	double	y;
	double	
}

typedef struct s_cub3d
{
	t_textures	textures;
	char		**map;
	void		*mlx;
	void		*win;
}		t_cub3d;

// src/parsing/file.c
void		ft_parse_file(t_cub3d *cub3d, char *filename);

// src/parsing/map.c
void		ft_parse_map(t_cub3d *cub3d, const int fd);

// src/parsing/background.c
void		ft_parse_colors(t_cub3d *cub3d, const int fd);

// src/parsing/texture.c
void		ft_parse_textures(t_cub3d *cub3d, const int fd);

// src/parsing/utils.c
char		*ft_get_path(const char *s);
const char	*ft_skip_space(const char *s);

// src/get_next_line.c
char		*get_next_line(int fd);

#endif
