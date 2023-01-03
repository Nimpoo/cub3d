/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:10:51 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/12 12:39:02 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t length)
{
	size_t	i;
	size_t	j;
	char	*resultat;

	i = 0;
	resultat = (char *)big;
	if (ft_strlen(little) == 0 || big == little)
		return (resultat);
	while (big[i] != '\0' && i < length)
	{
		j = 0;
		while (resultat[i + j] == little[j] && resultat[i + j]
			!= '\0' && little[j] != '\0' && i + j < length)
			j++;
		if (j == ft_strlen(little))
			return (resultat + i);
		i++;
	}
	return (NULL);
}
