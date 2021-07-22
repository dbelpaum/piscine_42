/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:28:25 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/21 14:29:02 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	g_current_level;

int	max2(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	btree_level_count2(t_btree *root)
{
	if (!root)
		return (0);
	return (max2(btree_level_count2(root->left),
			btree_level_count2(root->right)) + 1);
}

void	apply(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem),
			int level, int *levels)
{
	if (!root)
		return ;
	if (level > g_current_level)
		return ;
	if (level == g_current_level)
	{
		applyf(root->item, level, levels[level]);
		levels[level] = 0;
		return ;
	}
	apply(root->left, applyf, level + 1, levels);
	apply(root->right, applyf, level + 1, levels);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	count;
	int	level;
	int	*levels;

	count = btree_level_count2(root);
	levels = (int *)malloc(sizeof(int) * count);
	level = 0;
	if (!levels)
		return ;
	while (level < count)
	{
		g_current_level = level;
		level++;
		levels[level] = 1;
		apply(root, applyf, 0, levels);
	}
}
