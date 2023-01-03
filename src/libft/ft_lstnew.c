/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:58:15 by mayoub            #+#    #+#             */
/*   Updated: 2022/12/04 19:44:14 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_token	*ft_lstnew(char *content)
{
	t_token	*new_element;

	new_element = ft_calloc(1, sizeof(t_token));
	if (!new_element)
		return (NULL);
	new_element->content = ft_strdup(content);
	new_element->next = NULL;
	return (new_element);
}
