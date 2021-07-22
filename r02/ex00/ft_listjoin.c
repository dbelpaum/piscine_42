/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:55:16 by tbrowang          #+#    #+#             */
/*   Updated: 2021/07/18 12:11:57 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	len_words_list(t_words *begin_list)
{
	t_words	*cpy;
	int		i;

	cpy = begin_list;
	i = 0;
	while (cpy->next)
	{
		i += ft_strlen(cpy->word);
		cpy = cpy->next;
		i++;
	}
	return (i);
}

char	*ft_listjoin(t_words *begin_list)
{
	char	*str;

	str = malloc(sizeof(char) * len_words_list(begin_list));
	if (str == NULL)
		return (NULL);
	while (begin_list->next)
	{
		ft_strcat(str, begin_list->word);
		ft_strcat(str, " ");
		begin_list = begin_list->next;
	}
	if (begin_list->word != NULL)
	{
		ft_strcat(str, begin_list->word);
	}
	return (str);
}
