/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:48:24 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/20 13:00:36 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_antoi(char *str, int n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] && i < n)
	{	
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
