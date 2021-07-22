/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:35:14 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 21:49:09 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

t_config	argparser(int argc, char **argv)
{
	t_config	conf;

	conf.firstFileIdx = -1;
	conf.givenValue = 0;
	conf.readFromStdin = 0;
	if (argc < 3 || (ft_strcmp(argv[1], "-c") == 0 && argc < 4))
	{
		conf.readFromStdin = 1;
		if (argc == 2)
			conf.givenValue = ft_atoi(argv[1] + 2);
		else
			conf.givenValue = ft_atoi(argv[2]);
		return (conf);
	}
	if (ft_strcmp(argv[1], "-c") == 0)
	{
		conf.firstFileIdx = 3;
		conf.givenValue = ft_atoi(argv[2]);
	}
	else
	{
		conf.firstFileIdx = 2;
		conf.givenValue = ft_atoi(argv[1] + 2);
	}
	return (conf);
}

int	main(int argc, char**argv)
{
	t_config	conf;
	int			fd;
	int			fileindex;

	conf = argparser(argc, argv);
	fileindex = conf.firstFileIdx;
	if (conf.readFromStdin)
		ft_tail(conf.givenValue, 0);
	while (fileindex < argc && fileindex != -1)
	{
		fd = open(argv[fileindex], O_RDONLY);
		if (fd < 0)
		{
			exception_handler(argv[fileindex], argv[0]);
			close(fd);
			conf.firstFileIdx++;
		}
		else
		{
			file_headers(argv[fileindex], argc, conf.firstFileIdx, fileindex);
			ft_tail(conf.givenValue, fd);
		}
		fileindex++;
	}
	return (0);
}
