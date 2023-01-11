/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:36:04 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/11 15:44:30 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_path(char *path)
{
	if (open(path, O_RDONLY) == -1)
		return (error_bad_path(path, "Path invalid !"), 0);
	return (1);
}

int	ft_path(char *path)
{
	int	i;

	i = 0;
	while (!ft_isspace(path[i]))
		i++;
	while (ft_isspace(path[i]))
		i++;
	return (i);
}
