/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:47:18 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/10 15:43:06 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	error_bad_prefix(void)
{
	ft_putendl_fd("Error", STDERR);
	ft_putendl_fd("\e[31;1m[carré2d]: ba !\e[0m", STDERR);
}
