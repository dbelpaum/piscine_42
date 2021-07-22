/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:57:48 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/20 14:17:00 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	my_free(t_list *ptr, void (*free_fct)(void *))
{
	if (free_fct)
		free_fct(ptr->data);
	free(ptr);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *begin_list;
	temp = NULL;
	while (ptr)
	{
		if (cmp(ptr->data, data_ref) == 0)
		{
			if (temp)
				temp->next = ptr->next;
			else
				*begin_list = ptr->next;
			my_free(ptr, free_fct);
			if (temp)
				ptr = temp->next;
			else
				ptr = *begin_list;
		}
		else
		{
			temp = ptr;
			ptr = ptr->next;
		}
	}
}
