/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:20:46 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/16 23:21:56 by noalexan         ###   ########.fr       */
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

// src/ft_key_handler.c
void		ft_key_handler(t_cub3d *cub3d);
int			ft_keypress_handler(int key, t_cub3d *cub3d);
int			ft_keyrelease_handler(int key, t_cub3d *cub3d);

#endif
