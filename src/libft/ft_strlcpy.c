/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:37 by noalexan          #+#    #+#             */
/*   Updated: 2022/08/09 10:17:52 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t size)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!source || !destination)
		return (0);
	if (size > 0)
		while (source[++i] && i < size)
			if (source[i] != -1)
				destination[j++] = source[i];
	destination[j++] = '\0';
	return (ft_strlen(source));
}
