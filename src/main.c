/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/11 15:34:57 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_game	game;

	fd = open(av[1], O_RDONLY);
	ft_struct_game_init(&game);
	if (!pars_args(ac, av, fd))
		return (1);
	line = pars_path(fd, &game);
	if (!line)
		return (1);
	if (!pars_colors(&game.path, 1) || !pars_colors(&game.path, 0))
		return (1);
	if (!pars_map(fd, &game, line))
		return (1);
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre
// Version : 0.0.1
