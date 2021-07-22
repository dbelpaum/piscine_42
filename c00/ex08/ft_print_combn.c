/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:29:26 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/07 19:13:26 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_runtime(int n, char *tab);

int	ft_strlen(char *t)
{
	int		i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

void	ft_print_tab(char *t, int n)
{
	int	i;

	i = 0;
	if (t[0] == '9' + 1 - n)
		while (t[i] && t[i] != ',')
			write(1, &t[i++], 1);
	else
		while (t[i])
			write(1, &t[i++], 1);
}

void	ft_runtime(int n, char *tab)
{
	int	j;

	while (tab[0] <= '9' + 1 - n)
	{
		ft_print_tab(tab, n);
		j = n - 1;
		if (tab[j] < '9')
			tab[j]++;
		else
		{
			while (tab[j] == '9' - (n - j - 1) && j != 0)
				j--;
			if (j != n - 1 && j >= 0)
				tab[j++]++;
			while (j < n)
			{
				tab[j] = tab[j - 1] + 1;
				j++;
			}
		}		
	}
}

void	ft_print_combn(int n)
{
	char	tab[12];
	int		i;

	if (n < 1 || n > 9)
		return ;
	if (n == 1)
	{
		write(1, "0, 1, 2, 3, 4, 5, 6, 7, 8, 9", 28);
		return ;
	}
	i = 0;
	tab[0] = '0';
	while (++i < n)
		tab[i] = tab[i - 1] + 1;
	tab[i] = ',';
	tab[i + 1] = ' ';
	tab[i + 2] = 0;
	ft_runtime(n, tab);
}
