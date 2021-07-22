/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:42:31 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/07 14:58:44 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	if (ac < 1)
		ac = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(tab[i].str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}
