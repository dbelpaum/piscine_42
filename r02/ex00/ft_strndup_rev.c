/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrowang <contact@tbrowang.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:09:52 by tbrowang          #+#    #+#             */
/*   Updated: 2021/07/17 18:27:20 by tbrowang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strndup_rev(char *src, int n)
{
	int		i;
	int		j;
	char	*ret;

	ret = malloc((ft_strlen(src) - n + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = ft_strlen(src) - n + 1;
	ret[i--] = '\0';
	j = 0;
	while (src[i] && n > 0)
	{
		ret[j++] = src[i++];
		n--;
	}
	return (ret);
}
