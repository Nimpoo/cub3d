/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/13 16:36:47 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strchr(const char *string, int searchedChar)
{
	size_t	i;

	i = -1;
	if (!string)
		return (0);
	while (string[++i])
		if (string[i] == searchedChar)
			return (i);
	if (string[i] == searchedChar)
		return (i);
	return (0);
}
