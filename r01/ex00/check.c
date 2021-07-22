/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:06:38 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/11 11:25:34 by ctchen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_row_up(int **tab, int row)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 1;
	count = tab[0][row];
	while (j < 5)
	{
		if (tab[j][row] > max)
		{
			max = tab[j][row];
			count--;
		}
		j++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_row_down(int **tab, int row)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 4;
	count = tab[5][row];
	while (j > 0)
	{
		if (tab[j][row] > max)
		{
			max = tab[j][row];
			count--;
		}
		j--;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_line_left(int **tab, int line)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 1;
	count = tab[line][0];
	while (j < 5)
	{
		if (tab[line][j] > max)
		{
			max = tab[line][j];
			count--;
		}
		j++;
	}
	if (count != 0)
		return (0);
	return (1);
}

int	check_line_right(int **tab, int line)
{
	int	j;
	int	max;
	int	count;

	max = 0;
	j = 4;
	count = tab[line][5];
	while (j > 0)
	{
		if (tab[line][j] > max)
		{
			max = tab[line][j];
			count--;
		}
		j--;
	}
	if (count != 0)
		return (0);
	return (1);
}
