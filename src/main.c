/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:01:28 by Marwan❤Noah       #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/10 18:13:03 by mayoub           ###   ########.fr       */
=======
/*   Updated: 2023/01/03 15:04:16 by mayoub           ###   ########.fr       */
>>>>>>> c5507675181cf40e14d1f56e43c22cd6ebe8c99b
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

<<<<<<< HEAD
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
	if (!pars_colors(&game.path, 1) || !pars_colors(&game.path, 0))
		return (1);
=======
int	main(int argc, char **argv)
{
>>>>>>> c5507675181cf40e14d1f56e43c22cd6ebe8c99b
	return (0);
}

// Authors : Marwan Ayoub, Noah Alexandre
// Version : 0.0.1
