/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:43:38 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/07 19:04:15 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_address(unsigned long addr)
{
	char	*base;
	char	buffer[17];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (addr)
	{
		buffer[i] = base[addr % 16];
		addr = addr / 16;
		i++;
	}
	while (i < 16)
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
	write(1, ": ", 2);
}

void	ft_print_values(unsigned char *addr, int offset)
{
	int				i;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16 && offset - i)
	{
		ft_putchar(base[addr[i] / 16]);
		ft_putchar(base[addr[i] % 16]);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_chars(unsigned char *addr, int offset)
{
	int	i;

	i = 0;
	while (i < 16 && offset--)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long	p;
	unsigned int	offset;

	offset = 0;
	p = (unsigned long)addr;
	(void)size;
	while (offset < size)
	{
		ft_print_address(p + offset);
		ft_print_values((unsigned char *)(p + offset), size - offset);
		ft_print_chars((unsigned char *)(p + offset), size - offset);
		write(1, "\n", 1);
		offset += 16;
	}
	return (addr);
}
