/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:37:00 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/05 18:10:28 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		is_valid_base(char *base);
int		index_in_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);

char	*ft_zero(char	*base_to)
{
	char	*ret;

	ret = malloc (2 * sizeof(char));
	ret[0] = base_to[0];
	ret[1] = 0;
	return (ret);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
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

char	*ft_itoa_base(int nbr, char *base)
{
	int			i;
	char		ret[33];
	int			sign;
	char		*return_string;
	long int	n;

	i = 0;
	sign = 1;
	n = (long int)nbr;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n)
	{
		ret[i++] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	if (sign == -1)
		ret[i++] = '-';
	ret[i] = 0;
	ft_rev_int_tab(ret, ft_strlen(ret));
	return_string = ft_strdup(ret);
	return (return_string);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value_b10;
	char	*res;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	value_b10 = ft_atoi_base(nbr, base_from);
	if (value_b10 == 0)
		return (ft_zero(base_to));
	res = malloc((ft_strlen(ft_itoa_base(value_b10, base_to)) + 1)
			* sizeof(char));
	if (!res)
		return (NULL);
	res = ft_itoa_base(value_b10, base_to);
	return (res);
}
