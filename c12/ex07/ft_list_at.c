/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:43:46 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:53:34 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*ptr;

	ptr = begin_list;
	while (nbr)
	{
		ptr = ptr->next;
		if (!ptr)
			return (0);
		nbr--;
	}
	return (ptr);
}
