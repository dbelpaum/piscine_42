/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:14:36 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/20 15:33:09 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	min(int a, int b, int c)
{
	if (a <= c && a <= b)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	ft_print_map(t_map *map, t_point p, int max)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->lines)
	{
		x = 0;
		while (x < map->length)
		{
			if ((x < p.x - (max - 1) || x > p.x) || (y < p.y - (max - 1)
					|| y > p.y))
			{
				if (map->map[y][x] == 0)
					ft_putchar(map->obs);
				else
					ft_putchar(map->vide);
			}
			else
				ft_putchar(map->plein);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_solve(t_map *map)
{
	int		x;
	int		y;
	int		max;
	t_point	maxpos;

	y = -1;
	max = -1;
	while (++y < map->lines)
	{
		x = -1;
		while (++x < map->length)
		{
			if (map->map[y][x] == 1 && x > 0 && y > 0)
				map->map[y][x] = min(map->map[y - 1][x], map->map[y][x - 1],
						map->map[y - 1][x - 1]) + 1;
			if (max < map->map[y][x])
			{
				max = map->map[y][x];
				maxpos.x = x;
				maxpos.y = y;
			}
		}
	}
	ft_print_map(map, maxpos, max);
}
