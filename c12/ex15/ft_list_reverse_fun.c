/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:22:45 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 13:51:06 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at2(t_list *begin_list, unsigned int nbr)
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

int	ft_list_size2(t_list *begin_list)
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*opposite;
	void	*temp;
	int		i;
	int		j;

	i = 0;
	while (begin_list && ft_list_size2(begin_list) - i > 1)
	{
		j = ft_list_size2(begin_list) - i;
		opposite = ft_list_at2(begin_list, j - 1);
		temp = begin_list->data;
		begin_list->data = opposite->data;
		opposite->data = temp;
		begin_list = begin_list->next;
		i++;
	}
}
