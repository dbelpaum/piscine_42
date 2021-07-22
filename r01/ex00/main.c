/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:10:09 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:28 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) != 4 * 8 - 1)
		return (0);
	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	**tab;
	int	i;

	if (!check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	tab = init_tab(argv[1]);
	if (!tab)
		return (-1);
	if (ft_solve(tab, 0))
		ft_print_tab(tab);
	else
		write(2, "Error\n", 6);
	i = 0;
	while (i < 6)
		free(tab[i++]);
	free(tab);
	return (0);
}
