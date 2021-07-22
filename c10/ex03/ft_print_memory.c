/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:43:38 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/14 17:23:45 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/ft.h"

void	ft_print_address(unsigned long int addr, t_config conf)
{
	char	*base;
	char	buffer[9];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (addr)
	{
		buffer[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	while ((i < 8 && conf.hasOption) || (i < 7 && !conf.hasOption))
	{
		buffer[i] = '0';
		i++;
	}
	i--;
	while (i + 1)
	{
		write(1, &buffer[i], 1);
		i--;
	}
}

void	ft_print_values(unsigned char *addr, int offset, t_config conf)
{
	int				i;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16 && offset - i)
	{
		ft_putchar(base[addr[i] / 16], 1);
		ft_putchar(base[addr[i] % 16], 1);
		if (i != 15)
			write(1, " ", 1);
		if (i == 7 && conf.hasOption)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write (1, "  ", 2);
		if (i != 15)
			write(1, " ", 1);
		if (i == 7 && conf.hasOption)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_chars(unsigned char *addr, int offset)
{
	int	i;

	i = 0;
	write (1, "|", 1);
	while (i < 16 && offset--)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i], 1);
		else
			ft_putchar('.', 1);
		i++;
	}
	write (1, "|", 1);
}

void	print_line(t_config conf, unsigned char line[16],
	int length, int *index)
{
	ft_print_address(*index, conf);
	if (length > 0)
	{
		if (conf.hasOption)
			write(1, "  ", 2);
		else
			write(1, " ", 1);
		*index += length;
		ft_print_values(line, length, conf);
		if (conf.hasOption)
		{
			write(1, "  ", 2);
			ft_print_chars(line, length);
		}
	}
	write(1, "\n", 1);
}
