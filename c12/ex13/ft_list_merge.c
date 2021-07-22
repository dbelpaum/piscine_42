/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:14:41 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/19 16:04:44 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*ptr;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	ptr = *begin_list1;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = begin_list2;
}
