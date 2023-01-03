/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:15:31 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:40:49 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned long	position;
	int				delta;

	position = -1;
	while (++position < size)
	{
		delta = *(unsigned char *)pointer1++ - *(unsigned char *)pointer2++;
		if (delta)
			return (delta);
	}
	return (0);
}
