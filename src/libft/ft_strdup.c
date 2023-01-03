/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:08:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/11 15:01:06 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *source)
{
	char	*copy;

	if (!source)
		return (NULL);
	copy = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, ft_strlen(source));
	return (copy);
}

char	*ft_strdup_and_free(char *source)
{
	char	*copy;

	copy = ft_calloc(ft_strlen(source) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, ft_strlen(source));
	if (source)
		free(source);
	return (copy);
}

char	*ft_strldup(const char *source, size_t size)
{
	char	*copy;

	copy = ft_calloc(size + 1, sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, source, size);
	return (copy);
}
