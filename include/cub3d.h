/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:16 by Yoshi             #+#    #+#             */
/*   Updated: 2023/01/10 18:09:53 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>
# include <errno.h>

# include "libft.h"
# include "get_next_line.h"

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	0x35

typedef struct s_path{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*ceiling;
	char	*floor;
	int		c[3];
	int		f[3];
}	t_path;

typedef struct s_data{
	void	*n;
	void	*s;
	void	*w;
	void	*e;
	void	*f;
	void	*c;
}	t_data;

typedef struct s_game{
	t_data	data;
	t_path	path;
}	t_game;

// src/init.c
void	ft_struct_game_init(t_game *game);

// src/parsing/pars.c
int		pars_args(int ac, char **av, int fd);

// src/parsing/colors.c
int		pars_colors(t_path *path, int b);

// src/parsing/map.c
int		pars_map(int fd, t_game *game);
int		ft_path(char *path);

// src/error/error_arg.c
void	error_wrong_arguments(int bool, char *str);
void	error_bad_prefix(void);

#endif
