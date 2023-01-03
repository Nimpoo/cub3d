/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:09:55 by noalexan          #+#    #+#             */
/*   Updated: 2022/08/04 10:12:16 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstiter(t_token *lst, void (*f)(t_token *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(*f)(lst);
		lst = lst->next;
	}
}
