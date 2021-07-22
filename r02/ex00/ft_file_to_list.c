/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:05:30 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/17 22:11:13 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (NULL);
}

char	*ft_cut(int start, int end, char *str)
{
	char	*res;
	int		i;

	res = malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i] = str[start];
		start++;
		i++;
	}
	res[i] = 0;
	return (res);
}

void	skip_spaces(int *index, char *str)
{
	while (str[*index] == ' ')
		(*index)++;
}

t_list	*ft_parse_line(char *str)
{
	int		nblength;
	int		wordlength;
	int		i;
	t_list	*element;

	i = 0;
	while (is_number(str[i]))
		i++;
	if (i == 0)
		return (dict_error());
	nblength = i;
	skip_spaces(&i, str);
	if (str[i] != ':')
		return (dict_error());
	i++;
	skip_spaces(&i, str);
	wordlength = 0;
	while (str[i + wordlength])
		wordlength++;
	element = ft_create_elem(nblength, wordlength);
	element->number = ft_cut(0, nblength, str);
	element->word = ft_cut(i, wordlength + i, str);
	if (!element->word || !element->number)
		return (NULL);
	return (element);
}

t_list	*ft_file_to_list(int fd)
{
	char	**file_content_lines;
	t_list	*begin_list;
	int		i;
	t_list	*verif;

	begin_list = NULL;
	file_content_lines = ft_split(ft_process_file(fd), "\n");
	if (!file_content_lines)
		return (NULL);
	i = 0;
	while (file_content_lines[i])
	{
		verif = ft_parse_line(file_content_lines[i]);
		if (!verif)
			return (NULL);
		ft_list_push_back(&begin_list, verif);
		i++;
	}
	return (begin_list);
}
