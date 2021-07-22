/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:51:32 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 21:49:42 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], fd);
}
