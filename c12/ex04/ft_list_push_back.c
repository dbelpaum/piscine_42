/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:45:21 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/17 16:02:50 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last2(t_list *begin_list)
{
	t_list	*ptr;

	ptr = begin_list;
	if (!ptr)
		return (begin_list);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*l;
	t_list	*ptr;

	l = ft_create_elem(data);
	if (!(*begin_list))
		*begin_list = l;
	else
	{
		ptr = ft_list_last2(*begin_list);
		ptr->next = l;
	}
}
