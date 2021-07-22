/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:51:26 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/19 13:05:39 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	**str_to_matrix(char *str, char obst, char empty)
{
	int		trimm_offset;
	int		**int_matrix;
	char	chrs[2];

	chrs[0] = obst;
	chrs[1] = empty;
	trimm_offset = 0;
	while (str[trimm_offset] && str[trimm_offset] != '\n')
		trimm_offset++;
	int_matrix = ft_split_number(str + trimm_offset, "\n", chrs);
	if (!int_matrix)
		return (NULL);
	return (int_matrix);
}
