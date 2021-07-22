/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 12:12:09 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/18 20:31:30 by tbrowang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*trim_input(char *input)
{
	int	i;

	i = 0;
	while (input[i + 1] == '0' || ft_isspace(*input))
		i++;
	return (input + i);
}

void	build_three_digits(t_words **words_list, char *input, t_list *dico)
{
	int		i;
	char	*str;

	i = ft_strlen(input);
	if (ft_atoi(ft_strndup_rev(input, 2)) <= 19
		&& ft_atoi(ft_strndup_rev(input, 2)) >= 11)
	{
		list_push_back_w(words_list,
			search(ft_list_find_by_number(dico, ft_strndup_rev(input, 2))));
		if (ft_atoi(input) >= 100)
		{
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, "100")));
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, ft_strndup(input, 1))));
		}
		return ;
	}
	while (i > 0)
	{
		if (ft_strlen(input) > 3)
		{
			input = ft_strndup(input, 3);
		}
		if (i == 3)
		{
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico,
						ft_strndup_rev(input, 1))));
			input = ft_strndup(input, 2);
		}
		else if (i == 2)
		{
			str = ft_strndup_rev(input, 1);
			str = ft_strncat_malloc(str, "0", 2);
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, str)));
			free(str);
		}
		else
		{
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, "100")));
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, ft_strndup(input, 1))));
		}
		i--;
	}
}

void	build_two_digits(t_words **words_list, char *input, t_list *dico)
{
	char	*str;
	int		i;

	i = ft_strlen(input);
	if (ft_atoi(input) <= 19 && ft_atoi(input) >= 11)
	{
		list_push_back_w(words_list,
			search(ft_list_find_by_number(dico, ft_strndup_rev(input, 2))));
		return ;
	}
	while (i > 0)
	{
		if (i == 2)
		{
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico,
						ft_strndup_rev(input, 1))));
			input = ft_strndup(input, 2);
		}
		else
		{
			str = ft_strndup(input, 1);
			str = ft_strncat_malloc(str, "0", 2);
			list_push_back_w(words_list,
				search(ft_list_find_by_number(dico, str)));
			free(str);
		}
		i--;
	}
}

t_words	*build_string(char *input, t_list *dico)
{
	t_words	*words_list;
	char	*power;
	int		len;

	len = ft_strlen(input);
	input = trim_input(input);
	words_list = NULL;
	power = malloc(1);
	power[0] = '1';
	while (len > 0)
	{
		if (ft_strlen(power) >= 4)
			list_push_back_w(&words_list,
				search(ft_list_find_by_size(dico, ft_strlen(power))));
		power = ft_strncat_malloc(power, "000", ft_strlen(power) + 4);
		if (len == 1)
		{
			list_push_back_w(&words_list,
				search(ft_list_find_by_number(dico, input)));
		}
		else if (len == 2)
		{
			build_two_digits(&words_list, ft_strndup_rev(input, len), dico);
			break ;
		}
		else if (len >= 3)
			build_three_digits(&words_list, ft_strndup_rev(input, 3), dico);
		else
			build_three_digits(&words_list, ft_strndup_rev(input, len), dico);
		len -= 3;
		input = ft_strndup(input, len);
	}
	return (words_list);
}
