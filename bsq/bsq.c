/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:55:59 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/22 11:14:10 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_map	*ft_map_stdin(void)
{
	t_map	*map;
	char	*str_map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	str_map = process_file_stdin(0);
	if (ft_first_line(str_map, map)
		&& ft_map_ok(str_map, map) == map->lines)
		map->map = str_to_matrix(str_map, map->obs, map->vide);
	else
	{
		free(str_map);
		free(map);
		return (0);
	}
	return (map);
}

void	ft_use_stdin(void)
{
	t_map	*map;

	map = ft_map_stdin();
	if (!map)
		write(2, "map error\n", 10);
	else
	{
		ft_solve(map);
		free(map->map);
		free(map);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	if (argc == 1)
		ft_use_stdin();
	else
	{
		while (i < argc)
		{
			map = ft_map(argv[i]);
			if (map)
			{
				ft_solve(map);
				free(map->map);
				free(map);
			}
			else
				write(1, "map error\n", 10);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
