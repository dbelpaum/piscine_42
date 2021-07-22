/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:50:08 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 12:24:21 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	while (*begin_list)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = prev;
		prev = *begin_list;
		*begin_list = next;
	}
	*begin_list = prev;
}
