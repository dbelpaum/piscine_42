/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:19:51 by ctchen            #+#    #+#             */
/*   Updated: 2021/07/11 12:29:44 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_left(int **tab, int index, int value)
{
	while (index % 4 != 0)
	{
		index--;
		if (tab[index / 4 + 1][index % 4 + 1] == value)
			return (0);
	}
	return (1);
}

int	ft_up(int **tab, int index, int value)
{
	while (index / 4 != 0)
	{
		index -= 4;
		if (tab[index / 4 + 1][index % 4 + 1] == value)
			return (0);
	}
	return (1);
}

int	is_valid_value(int **tab, int index, int value)
{
	if (!ft_up(tab, index, value) || !ft_left(tab, index, value))
	{
		return (0);
	}
	return (1);
}

int	is_valid_array(int **tab)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (!check_row_up(tab, i) || !check_row_down(tab, i)
			|| !check_line_left(tab, i) || !check_line_right(tab, i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
