/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:22:30 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/10 15:56:22 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_save_param(char *line, t_game *game)
{
	// ((void) line, (void) game);
	if (!ft_strncmp("NO ", line, 3))
		game->path->north = ft_strdup(line);
}

int	ft_check_param(char *line, t_game *game)
{
	(void) game;
	printf("%s\n", line);
	if (!ft_strncmp("NO ", line, 3) || !ft_strncmp("SO ", line, 3)
		|| !ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3)
		|| !ft_strncmp("C ", line, 2) || !ft_strncmp("F ", line, 2))
		return (ft_save_param(line, game), 1);
	return (0);
}

int	pars_map(int fd, t_game *game)
{
	char	*line;
	int		i;
	int		nbr_config;

	line = get_next_line(fd);
	i = 0;
	nbr_config = 0;
	while (line[i] != '1')
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] == '\n' || !line[i])
			nbr_config--;
		else if (!ft_check_param(line + i, game))
			return (error_bad_prefix(), 0);
		nbr_config++;
		i = 0;
		line = get_next_line(fd);
	}
	if (nbr_config != 6)
		return (error_bad_prefix(), 0);
	return (1);
}
