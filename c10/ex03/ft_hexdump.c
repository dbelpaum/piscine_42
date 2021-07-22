/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:40:38 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/14 18:42:25 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	get_next_line(t_config *conf, unsigned char line[16], int	*currentFile,
	int *fd)
{
	unsigned char	buffer[16];
	int				readChars;

	if (*fd == 0)
		*fd = get_next_valid_file(currentFile, *conf, fd);
	if (*fd == -1)
		return (-1);
	reset_string(line);
	reset_string(buffer);
	readChars = read(*fd, buffer, 16);
	while (readChars < 16 && !is_last_file(*currentFile, *conf)
		&& readChars != -1)
	{
		close(*fd);
		*currentFile = *currentFile + 1;
		*fd = get_next_valid_file(currentFile, *conf, fd);
		if (*fd > 0)
			readChars += read(*fd, buffer + readChars, 16 - readChars);
	}
	ft_strncat(line, buffer, readChars);
	return (readChars);
}

void	flush_buffer(t_config conf, unsigned char *line, int length, int *index)
{
	if (length == -1)
		return ;
	print_line(conf, line, length, index);
	if (length != 16 && length != 0)
	{
		ft_print_address(*index, conf);
		write(1, "\n", 1);
	}
}

int	check_save(t_config *conf, unsigned char *str, int *index)
{
	if (ft_strncmp(conf->save, str) != 0)
	{
		conf->wildcardWritten = 0;
		return (1);
	}
	if (conf->wildcardWritten)
	{
		*index += 16;
		return (0);
	}
	write(1, "*\n", 2);
	conf->wildcardWritten = 1;
	*index += 16;
	return (0);
}

void	ft_hexdump(t_config *conf)
{
	unsigned char	line[16];
	int				currentFile;
	int				readAmount;
	int				fd;
	int				index;

	fd = 0;
	index = 0;
	readAmount = 16;
	currentFile = 0;
	reset_string(line);
	while (readAmount == 16)
	{
		readAmount = get_next_line(conf, line, &currentFile, &fd);
		if (readAmount == 16 && check_save(conf, line, &index))
			print_line(*conf, line, readAmount, &index);
		reset_string(conf->save);
		ft_strncopy(conf->save, line, readAmount);
	}
	check_bad_file_descriptor(*conf);
	flush_buffer(*conf, line, readAmount, &index);
}

void	check_bad_file_descriptor(t_config conf)
{
	int	i;
	int	fd;

	i = conf.firstFileIdx;
	while (i < conf.lastFileIdx + 1)
	{
		fd = open(conf.argv[i], O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			return ;
		}
		close(fd);
		i++;
	}
	fd = open(conf.argv[i - 1], O_RDONLY);
	read(fd, "", 1);
	exception_handler(conf.argv[i - 1], conf.argv[0]);
}
