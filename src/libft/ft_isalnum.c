/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:51:57 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/23 09:56:15 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int character)
{
	if ('a' <= character && character <= 'z')
		return (1);
	if ('A' <= character && character <= 'Z')
		return (1);
	if ('0' <= character && character <= '9')
		return (1);
	return (0);
}
