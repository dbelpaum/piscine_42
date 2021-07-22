/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:32:03 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/03 10:26:16 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;
	int	i;

	res = 1;
	i = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (i <= nb)
	{
		res *= i;
		i++;
	}
	return (res);
}
