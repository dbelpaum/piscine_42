/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:14:00 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/02 14:49:43 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstrnewline(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
}

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

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_strswap(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (++i < argc)
		ft_putstrnewline(argv[i]);
}
