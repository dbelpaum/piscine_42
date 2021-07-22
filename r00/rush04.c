/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 10:45:33 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/03 11:07:47 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(char left, char center, char right, int x)
{
	ft_putchar(left);
	x--;
	while (x > 1)
	{
		ft_putchar(center);
		x--;
	}
	if (x == 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush04(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	ft_putline('A', 'B', 'C', x);
	y--;
	while (y > 1)
	{
		ft_putline('B', ' ', 'B', x);
		y--;
	}
	if (y == 1)
		ft_putline('C', 'B', 'A', x);
}
