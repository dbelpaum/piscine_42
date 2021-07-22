/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:45:08 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 15:21:47 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>
typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;
t_btree	*btree_create_node(void *item);
#endif