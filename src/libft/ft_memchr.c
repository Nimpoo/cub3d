/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:48:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:43:31 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		if (((unsigned char *)memoryBlock)[i] == (unsigned char)searchedChar)
			return ((void *)&memoryBlock[i]);
	return (NULL);
}
