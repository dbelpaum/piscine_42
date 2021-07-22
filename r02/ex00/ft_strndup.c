/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:30:35 by tbrowang          #+#    #+#             */
/*   Updated: 2021/07/18 12:11:02 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i] != '\0' && n > 0 )
	{
		dup[i] = s[i];
		i++;
		n--;
	}
	dup[i] = '\0';
	return (dup);
}
