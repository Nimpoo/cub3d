/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:12:52 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 08:46:40 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

static int	ft_count_delimitor(const char *s, const char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (j)
		j++;
	return (j);
}

static int	ft_get_segment(char **segment, const char *s, const char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	*segment = ft_strldup(s, i);
	return (i + 1);
}

char	**ft_split(const char *s, const char c)
{
	char	**split;
	int		j;
	int		i;
	int		l;

	if (!s)
		return (NULL);
	i = ft_count_delimitor(s, c);
	split = ft_calloc((i + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	j = -1;
	l = 0;
	while (++j < i)
		l += ft_get_segment(split + j, s + l, c);
	return (split);
}
