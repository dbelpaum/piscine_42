/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:12:31 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 22:24:33 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * length);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ret[i] = f(tab[i]);
		i++;
	}
	return (ret);
}
