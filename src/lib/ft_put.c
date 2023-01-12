/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:10 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/11 16:34:19 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put(const char *s, const int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_put3(const char *s1, const char *s2, const char *s3, const int fd)
{
	ft_put(s1, fd);
	ft_put(s2, fd);
	ft_put(s3, fd);
}
