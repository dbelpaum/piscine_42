/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:15:26 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/03 18:24:12 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	i;

	if (min >= max)
		return (NULL);
	ret = malloc((max - min) * sizeof(int));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		ret[i] = min + i;
		i++;
	}
	return (ret);
}
