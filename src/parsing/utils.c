/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 08:57:42 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 08:57:54 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_get_path(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (ft_strldup(s, i));
}

const char	*ft_skip_space(const char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (s + i);
}
