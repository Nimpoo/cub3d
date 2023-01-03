/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:57:52 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:23:48 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*result;

	result = malloc(elementCount * elementSize);
	if (!result)
		return (NULL);
	ft_bzero(result, (elementCount * elementSize));
	return (result);
}
