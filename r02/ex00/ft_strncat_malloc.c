/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:19:29 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/17 20:17:44 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strncat_malloc(char *dest, char *src, int n)
{
	int		i;
	int		destlen;
	char	*ret;

	ret = malloc((ft_strlen(dest) + ft_strlen(src) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (dest[++i])
		ret[i] = dest[i];
	ret[i] = 0;
	destlen = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		ret[destlen + i] = src[i];
		i++;
	}
	ret[destlen + i] = 0;
	free(dest);
	return (ret);
}
