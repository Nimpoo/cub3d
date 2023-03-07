/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:36:52 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/29 07:19:21 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

const char	*ft_skip_space(const char *s);

int	ft_atoi(const char *s)
{
	const char	*ss = ft_skip_space(s);
	int			result;
	int			i;

	i = -1;
	result = 0;
	while (ss[++i] && '0' <= ss[i] && ss[i] <= '9')
	{
		result *= 10;
		result += ss[i] - '0';
	}
	if (ft_skip_space(ss + i)[0])
	{
		ft_put("Error\nThere is letter(s) in rgb color\n", 2);
		exit(7);
	}
	return (result);
}
