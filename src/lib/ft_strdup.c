/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:14 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 08:45:28 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

char	*ft_strldup(const char *s, const int n)
{
	char	*dup;
	int		i;

	dup = ft_calloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < n)
		dup[i] = s[i];
	return (dup);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		dup[i] = s[i];
	return (dup);
}

char	*ft_strdup_and_free(char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		dup[i] = s[i];
	free(s);
	return (dup);
}
