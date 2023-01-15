/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:20:46 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/15 16:42:06 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../minilibx/mlx.h"
# include "lib.h"

# define W_WIDTH 800
# define W_HEIGHT 500

# define E_KEYPRESS 2
# define E_KEYRELEASE 3
# define E_QUIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

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
	void		*screen;
	char		*screen_addr;
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
