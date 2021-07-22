/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:10:01 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/21 14:29:04 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*res;

	res = NULL;
	if (!root)
		return (NULL);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (res)
		return (res);
	if (cmpf(root->item, data_ref) == 0)
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
