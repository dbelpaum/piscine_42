/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:56:30 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:36:46 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*ptr;

	ptr = begin_list;
	if (!ptr)
		return (NULL);
	while (ptr->next)
	{
		if (cmp(ptr->data, data_ref) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	if (cmp(ptr->data, data_ref) == 0)
		return (ptr);
	return (NULL);
}
