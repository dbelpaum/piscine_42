/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:18:01 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:39:28 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	void	*temp;

	ptr = *begin_list;
	if (!ptr)
		return ;
	while (ptr->next)
	{
		if (cmp(ptr->data, ptr->next->data) > 0)
		{
			temp = ptr->data;
			ptr->data = ptr->next->data;
			ptr->next->data = temp;
			ptr = *begin_list;
		}
		else
			ptr = ptr->next;
	}
}
