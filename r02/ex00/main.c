/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:25:27 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 20:19:04 by tbrowang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	check_input(int argc, char **argv, int *fd)
{
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
		*fd = open(argv[1], O_RDONLY);
	else
		*fd = open("numbers.dict", O_RDONLY);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*begin_list;
	t_words	*words_list;

	if (check_input(argc, argv, &fd) == 0)
		return (0);
	if (fd < 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		begin_list = ft_file_to_list(fd);
	}
	begin_list = ft_file_to_list(fd);
	words_list = build_string(argv[2], begin_list);
	ft_putstr(ft_listjoin(words_list));
	ft_putstr("\n");
}
