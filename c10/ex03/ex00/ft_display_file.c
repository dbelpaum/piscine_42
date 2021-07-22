/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:16:45 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/08 14:32:55 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	display_file(char *filename)
{
	int		fd;
	int		length;
	char	buffer[256];

	length = 1;
	fd = open(filename, O_RDONLY);
	while (length > 0)
	{
		length = read(fd, buffer, 256);
		write(1, buffer, length);
	}
	close(fd);
}
