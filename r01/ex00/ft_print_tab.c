/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:32:54 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/11 12:29:02 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_tab(int **tab)
{
	int	index;

	index = 0;
	while (index < 16)
	{
		ft_putchar(tab[index / 4 + 1][index % 4 + 1] + '0');
		if ((index + 1) % 4 == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		index++;
	}
}
