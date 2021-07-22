/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:39:32 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:47:42 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;

	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		elem = ft_create_elem(data);
		if (!elem)
			return ;
		elem->next = *begin_list;
		*begin_list = elem;
	}
	else
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
}
