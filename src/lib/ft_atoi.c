/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 00:36:52 by noalexan          #+#    #+#             */
/*   Updated: 2023/01/12 08:46:16 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

int	ft_atoi(const char *s)
{
	int	result;
	int	i;

	i = -1;
	result = 0;
	while (s[++i] && '0' <= s[i] && s[i] <= '9')
	{
		result *= 10;
		result += s[i] - '0';
	}
	if (s[i] && !ft_isspace(s[i]))
	{
		ft_put("error: map invalid\n", 2);
		exit(7);
	}
	return (result);
}
