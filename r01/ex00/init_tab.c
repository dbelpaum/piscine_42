/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:58:17 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 18:41:59 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_borders(int **tab, char *str)
{
	int	strindex;
	int	tabindex;

	strindex = 0;
	tabindex = 1;
	while (strindex < 31)
	{
		if (strindex < 7)
			tab[0][tabindex] = str[strindex] - '0';
		else if (strindex < 15)
			tab[5][tabindex] = str[strindex] - '0';
		else if (strindex < 23)
			tab[tabindex][0] = str[strindex] - '0';
		else if (strindex < 31)
			tab[tabindex][5] = str[strindex] - '0';
		tabindex++;
		if (tabindex % 5 == 0)
			tabindex = 1;
		strindex += 2;
	}
}

int	**init_tab(char *str)
{
	int	index;
	int	**tab;
	int	i;

	tab = malloc(6 * sizeof(int *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 6)
	{
		tab[i] = malloc(6 * sizeof(int));
		if (!tab)
			return (NULL);
		i++;
	}
	index = 0;
	while (index < 36)
	{
		tab[index / 6][index % 6] = 0;
		index++;
	}
	init_borders(tab, str);
	return (tab);
}
