/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:54:06 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/12 17:01:52 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strswap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i + 1])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_strswap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
