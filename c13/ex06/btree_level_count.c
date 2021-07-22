/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:10:28 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/19 19:40:32 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (max(btree_level_count(root->left),
			btree_level_count(root->right)) + 1);
}
