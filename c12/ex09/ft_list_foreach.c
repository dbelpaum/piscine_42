/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:52:22 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:34:38 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*ptr;

	if (!begin_list || !f)
		return ;
	ptr = begin_list;
	while (ptr->next)
	{
		f(ptr->data);
		ptr = ptr->next;
	}
	f(ptr->data);
}
