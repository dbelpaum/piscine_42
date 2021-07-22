/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:39:50 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/12 20:51:51 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*ptr;

	ptr = begin_list;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
