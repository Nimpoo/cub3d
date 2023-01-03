/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:05:48 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/28 11:48:31 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ecriture2(char *result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2)
	{
		if (s1)
			j = ft_strlen(result);
		while (i < ft_strlen(s2))
		{
			((char *)result)[j] = ((char *)s2)[i];
			i++;
			j++;
		}
	}
	result[j] = '\0';
	return (result);
}

static char	*ecriture(char *result, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1)
	{
		while (i < ft_strlen(s1))
		{
			((char *)result)[i] = ((char *)s1)[i];
			i++;
		}
	}
	return (ecriture2(result, s1, s2));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	if (!s1)
		result = ft_calloc(ft_strlen(s2) + 1, sizeof(char));
	else if (!s2)
		result = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	else
		result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
	if (!result)
		return (NULL);
	ecriture(result, s1, s2);
	return (result);
}
