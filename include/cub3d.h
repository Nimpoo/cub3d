/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:16 by Yoshi             #+#    #+#             */
/*   Updated: 2023/01/08 16:01:46 by mayoub           ###   ########.fr       */
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

# define STDIN  STDIN_FILENO
# define STDOUT STDOUT_FILENO
# define STDERR STDERR_FILENO

# define UP		13
# define DOWN	1
# define LEFT	0
# define RIGHT	2
# define ESC	0x35

// src/parsing/pars_args.c
int		pars_args(int ac, char **av, int fd);

// src/error/error_arg.c
void	error_wrong_arguments(int bool, char *str);

#endif
