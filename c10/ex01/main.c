/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:35:14 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 21:49:40 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	ft_strlen(char *str);

int	main(int argc, char**argv)
{
	int	fd;
	int	filecount;

	if (argc == 1)
		display_file(0);
	filecount = 1;
	while (filecount < argc)
	{
		if ((ft_strlen(argv[filecount]) == 1 && argv[filecount][0] == '-')
			|| (ft_strlen(argv[filecount]) == 2 && argv[filecount][0] == '-'
			&& argv[filecount][1] == '-'))
			display_file(0);
		else
		{
			fd = open(argv[filecount], O_RDONLY);
			if (fd < 0)
			{
				exception_handler(argv[filecount], argv[0]);
				close(fd);
			}
			else
				display_file(fd);
		}
		filecount++;
	}
}
