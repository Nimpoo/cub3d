/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:36:02 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/11 15:25:47 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	pars_map(int fd, t_game *game, char *line)
{
	int	i;

	(void) game;
	(void) fd;
	i = 0;
	printf("line = [%s]\n", line);
	while (line[i] != '1' && line[i])
		i++;
	return (1);
}