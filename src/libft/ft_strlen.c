/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:39 by noalexan          #+#    #+#             */
/*   Updated: 2022/08/01 10:49:03 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == -1)
			j++;
	return (i + j);
}
