/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:46 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/24 18:37:09 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int character)
{
	if (65 <= character && character <= 90)
		return (character + 32);
	return (character);
}
