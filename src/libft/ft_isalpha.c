/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:00 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/23 09:57:02 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	if ('a' <= character && character <= 'z')
		return (1);
	if ('A' <= character && character <= 'Z')
		return (1);
	return (0);
}
