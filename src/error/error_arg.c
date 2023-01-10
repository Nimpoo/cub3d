/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:02:25 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/09 14:18:20 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_wrong_arguments(int bool, char *str)
{
	if (bool == 0)
	{
		ft_putendl_fd("Error", STDERR);
		ft_putendl_fd("\e[31;1m[carré2d]: wrong nbr of arguments !\e[0m", STDERR);
	}
	else if (bool == 1)
	{
		ft_putendl_fd("Error", STDERR),
		(ft_putstr_fd("\e[31;1m[carré2d]: ", STDERR), ft_putstr_fd(str, STDERR));
		ft_putendl_fd(": invalid argument !", STDERR);
	}
	else if (bool == 2)
	{
		ft_putendl_fd("Error", STDERR);
		(ft_putstr_fd("\e[31;1m[carré2d]: ", STDERR), ft_putstr_fd(str, STDERR));
		ft_putstr_fd(": wrong extension !\n", STDERR);
		ft_putendl_fd("\e[1;32mPlz use a valid [CUB] file. THX U\e[0m", STDERR);
	}
}
