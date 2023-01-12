/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:17:23 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 08:40:08 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

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
	if (result[pos] == '\n')
		result[pos] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		add_buffer(&save, buffer);
		if (there_is_a_end_of_line(save) != -1)
			return (get_line(&save));
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (get_line(&save));
}
