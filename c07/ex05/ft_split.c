/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:41:35 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/06 15:52:59 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	return (count + 1);
}

char	*get_next_word(int *index, char *str, char *charset)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (char_is_in_charset(str[*index], charset))
		(*index)++;
	while (!char_is_in_charset(str[*index + len], charset) && str[*index + len])
		len++;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i++] = str[*index];
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		ac;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ac = get_ac(str, charset);
	res = malloc(ac * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < ac - 1)
		res[i++] = get_next_word(&j, str, charset);
	res[i] = 0;
	return (res);
}
