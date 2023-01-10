/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
/*   Updated: 2023/01/10 15:58:40 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	fd = open(av[1], O_RDONLY);
	if (!pars_args(ac, av, fd))
		return (1);
	ft_struct_game_init(&game);
	if (!pars_map(fd, &game))
		return (1);
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre
// Version : 0.0.1
