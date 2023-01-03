/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:19:17 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/29 17:08:38 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*m;
	size_t	i;

	m = ft_calloc(n + 1, sizeof(char));
	if (!m)
		return (NULL);
	i = -1;
	while (++i < n)
		m[i] = s[i];
	return (m);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s) || !s)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > ft_strlen(s))
		return (ft_strdup(&s[start]));
	return (ft_strndup(&s[start], len));
}
