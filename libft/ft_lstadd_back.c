/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbolat <cbolat@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:49:32 by cbolat            #+#    #+#             */
/*   Updated: 2022/10/16 17:49:33 by cbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	(temp) = malloc(sizeof(t_list));
	if (!(temp))
		return ;
	temp = *lst;
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
	return ;
}
