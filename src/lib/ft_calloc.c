/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:33:33 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/11 17:50:01 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t elementSize)
{
	void	*a;

	a = malloc(elementSize);
	if (!a)
		return (NULL);
	while (elementSize--)
		((char *) a)[elementSize] = 0;
	return (a);
}
