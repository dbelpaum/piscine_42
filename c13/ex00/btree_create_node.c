/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:45:05 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 15:21:12 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*elem;

	elem = malloc(sizeof(struct s_btree));
	if (!elem)
		return (NULL);
	elem->left = NULL;
	elem->right = NULL;
	elem->item = item;
	return (elem);
}
