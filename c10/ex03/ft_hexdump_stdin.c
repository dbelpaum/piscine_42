/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 18:41:56 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/16 22:21:32 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

void	ft_print_address_newline(int *index, t_config *conf,
			unsigned char line[16], int length)
{
	if (length == 0)
		return ;
	flush_buffer(*conf, line, length, index);
	if (*index % 16 == 0)
	{
		ft_print_address(*index, *conf);
		write(1, "\n", 1);
	}
}

int	check_save_stdin(t_config *conf, unsigned char *str, int *index)
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

void	ft_hexdump_stdin(t_config *conf, int *index)
{
	int				hasRead;
	unsigned char	buffer[2];
	int				length;
	unsigned char	line[16];

	length = 0;
	hasRead = 1;
	while (hasRead > 0)
	{
		hasRead = read(0, buffer, 1);
		if (hasRead && length < 16)
		{
			line[length] = buffer[0];
			length++;
		}
		else if (hasRead && length == 16)
		{
			if (check_save_stdin(conf, line, index))
				print_line(*conf, line, length, index);
			ft_strncopy(conf->save, line, 16);
			line[0] = buffer[0];
			length = 1;
		}
	}
	ft_print_address_newline(index, conf, line, length);
}
