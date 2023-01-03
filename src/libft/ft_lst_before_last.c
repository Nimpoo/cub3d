/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_before_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:44:44 by noalexan          #+#    #+#             */
/*   Updated: 2022/07/19 15:38:29 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_token	*ft_lst_before_last(t_token *lst)
{
	if (lst && lst->next)
		while (lst->next->next)
			lst = lst->next;
	return (lst);
}
