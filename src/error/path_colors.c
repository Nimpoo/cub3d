/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:47:18 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/11 15:50:12 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_color(int color, char *message)
{
	ft_putendl_fd("Error", STDERR);
	ft_putendl_fd("\e[31;1m[carré2d]: ", STDERR);
	ft_putendl_fd(message, STDERR);
	(ft_putstr_fd("\e[1;33m\"", STDERR), ft_putnbr_fd(color, STDERR));
	ft_putendl_fd("\"\e[0m", STDERR);
}

void	error_bad_path(char *str, char *message)
{
	ft_putendl_fd("Error", STDERR);
	ft_putstr_fd("\e[31;1m[carré2d]: ", STDERR);
	(ft_putendl_fd(message, STDERR), ft_putstr_fd("\e[1;33m\"", STDERR));
	if (!str)
		ft_putstr_fd("(null)", STDERR);
	else
		ft_putstr_fd(str, STDERR);
	ft_putendl_fd("\"\e[0m", STDERR);
}
