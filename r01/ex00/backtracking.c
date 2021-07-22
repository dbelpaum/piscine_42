/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:16:25 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/11 12:30:25 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_solve(int **tab, int index)
{
	int	value;

	if (index == 16 && is_valid_array(tab))
	{
		return (1);
	}
	if (index < 16)
	{
		value = 1;
		while (value < 5)
		{
			if (is_valid_value(tab, index, value))
			{
				tab[index / 4 + 1][index % 4 + 1] = value;
				if (ft_solve(tab, index + 1))
					return (1);
			}
			value++;
		}
	}
	return (0);
}
