/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:47:22 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/09 18:47:22 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	is_last_file(int fileIndex, t_config conf)
{
	if (fileIndex >= conf.lastFileIdx - conf.firstFileIdx)
		return (1);
	return (0);
}

int	get_next_valid_file(int	*currentFile, t_config conf, int *fd)
{
	while (!is_last_file(*currentFile - 1, conf))
	{
		*fd = open(conf.argv[*currentFile + conf.firstFileIdx], O_RDONLY);
		if (*fd < 0)
		{
			exception_handler(conf.argv[*currentFile + conf.firstFileIdx],
				conf.argv[0]);
			close(*fd);
		}
		else
			return (*fd);
		(*currentFile)++;
	}
	return (-1);
}

void	exception_handler(char *filename, char *binary_name)
{
	write(STDERR, basename(binary_name), ft_strlen(basename(binary_name)));
	write(STDERR, ": ", 2);
	write(STDERR, filename, ft_strlen(filename));
	write(STDERR, ": ", 2);
	ft_putstr(strerror(errno), STDERR);
	write(STDERR, "\n", 1);
}

t_config	argparser(int argc, char **argv)
{
	t_config	conf;

	conf.readFromStdin = 0;
	conf.firstFileIdx = -1;
	conf.lastFileIdx = -1;
	conf.hasOption = 0;
	conf.argv = argv;
	if (argc < 2 || (argc < 3 && ft_strcmp("-C", argv[1]) == 0))
		conf.readFromStdin = 1;
	if (argc >= 2 && ft_strcmp("-C", argv[1]) == 0)
		conf.hasOption = 1;
	if (conf.hasOption && !conf.readFromStdin)
		conf.firstFileIdx = 2;
	else if (!conf.readFromStdin)
		conf.firstFileIdx = 1;
	if (!conf.readFromStdin && !conf.hasOption)
		conf.lastFileIdx = argc - conf.firstFileIdx;
	else if (!conf.readFromStdin && conf.hasOption)
		conf.lastFileIdx = argc - conf.firstFileIdx + 1;
	conf.save = malloc(16 * sizeof(unsigned char));
	reset_string(conf.save);
	conf.wildcardWritten = 0;
	return (conf);
}

int	main(int argc, char **argv)
{
	t_config	conf;
	int			index;

	index = 0;
	conf = argparser(argc, argv);
	if (conf.readFromStdin)
		ft_hexdump_stdin(&conf, &index);
	else
		ft_hexdump(&conf);
	return (0);
}
