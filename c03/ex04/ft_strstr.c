/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:20:50 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/06/30 19:50:53 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (to_find[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
