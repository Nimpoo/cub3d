/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:07:42 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/10 15:41:33 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

int	there_is_a_end_of_line(char *save)
{
	int	i;

	i = -1;
	while (save[++i])
		if (save[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_substr_gnl(char *save, int start, int end)
{
	char	*result;
	int		i;

	if (start > end)
		return (NULL);
	result = malloc((end - start + 2) * sizeof(char));
	i = -1;
	while (++i + start <= end)
		result[i] = save[i + start];
	result[i] = '\0';
	return (result);
}

void	add_buffer(char **save, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	if (!*save)
		*save = ft_substr_gnl("", 0, 0);
	i = -1;
	j = 0;
	new = malloc((ft_strlen(*save) + ft_strlen(buffer) + 1) * sizeof(char));
	while ((*save)[++i])
		new[i] = (*save)[i];
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	if (*save)
		free(*save);
	*save = new;
}

char	*get_line(char **save)
{
	char	*new;
	char	*result;
	int		pos;

	if (!*save)
		return (NULL);
	pos = there_is_a_end_of_line(*save);
	if (pos == -1)
		pos = ft_strlen(*save) - 1;
	result = ft_substr_gnl(*save, 0, pos);
	new = ft_substr_gnl(*save, pos + 1, ft_strlen(*save) - 1);
	if (*save)
		free(*save);
	*save = new;
	result[pos] = 0;
	return (result);
}
