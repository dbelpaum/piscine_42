/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:33:35 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/12 20:38:37 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*l;

	l = ft_create_elem(data);
	if (l)
	{
		if (*begin_list)
			l->next = *begin_list;
		*begin_list = l;
	}
}
