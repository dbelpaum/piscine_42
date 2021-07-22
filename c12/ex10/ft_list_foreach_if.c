/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:54:25 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/16 12:56:12 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
	*data_ref, int (*cmp)())
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr->next)
	{
		if (cmp(ptr->data, data_ref) == 0)
			f(ptr->data);
		ptr = ptr->next;
	}
	if (cmp(ptr->data, data_ref) == 0)
		f(ptr->data);
}
