/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/22 15:34:07 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	if (destination && source)
	{
		a = (char *)destination;
		b = (char *)source;
		while (i < size)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (destination);
}
