/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:49:28 by noahalexand       #+#    #+#             */
/*   Updated: 2022/07/22 15:50:24 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstdelone(t_token *lst, int del(char *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
