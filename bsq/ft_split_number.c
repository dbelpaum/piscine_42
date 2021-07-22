/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:35 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/20 14:37:43 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	char_is_in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	get_ac(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (char_is_in_charset(str[i], charset))
			i++;
		if (!char_is_in_charset(str[i], charset) && str[i])
		{
			count++;
			while (!char_is_in_charset(str[i], charset) && str[i])
				i++;
		}
	}
	return (count);
}

int	*get_next_tab(int *index, char *str, char *charset, char chrs[2])
{
	int		len;
	int		*res;
	int		i;

	i = 0;
	len = 0;
	while (char_is_in_charset(str[*index], charset))
		(*index)++;
	while (!char_is_in_charset(str[*index + len], charset) && str[*index + len])
		len++;
	res = (int *)malloc((len) * sizeof(int));
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (str[*index] == chrs[0])
			res[i++] = 0;
		else
			res[i++] = 1;
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

int	**ft_split_number(char *str, char *charset, char chrs[2])
{
	int		**res;
	int		ac;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ac = get_ac(str, charset);
	res = (int **)malloc(ac * sizeof(int *));
	if (!res)
		return (NULL);
	while (i < ac)
	{
		res[i++] = get_next_tab(&j, str, charset, chrs);
		if (!res[i - 1])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
	}
	return (res);
}
