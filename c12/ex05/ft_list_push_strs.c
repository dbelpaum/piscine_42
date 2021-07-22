/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:15:20 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 17:32:31 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*first;
	int		i;

	i = 0;
	if (size == 0 || !*strs)
		return (NULL);
	first = NULL;
	while (size > i)
	{
		list = ft_create_elem(strs[i]);
		if (!list)
			return (first);
		list->next = first;
		first = list;
		i++;
	}
	return (first);
}
