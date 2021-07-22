/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:39:00 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/10 21:49:03 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

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
