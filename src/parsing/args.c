/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:57:41 by mayoub            #+#    #+#             */
/*   Updated: 2023/01/09 14:19:32 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	pars_extension(char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	if (arg[i--] != 'b')
		return (0);
	if (arg[i--] != 'u')
		return (0);
	if (arg[i--] != 'c')
		return (0);
	if (arg[i--] != '.')
		return (0);
	return (1);
}

int	pars_name(char *arg, int fd)
{
	if (fd == -1)
		return (error_wrong_arguments(1, arg), 0);
	if (!pars_extension(arg))
		return (error_wrong_arguments(2, arg), 0);
	return (1);
}

int	pars_args(int ac, char **av, int fd)
{
	if (ac != 2)
		return (error_wrong_arguments(0, NULL), 0);
	if (!pars_name(*++av, fd))
		return (0);
	return (1);
}
