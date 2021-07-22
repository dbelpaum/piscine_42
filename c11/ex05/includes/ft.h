/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:53:22 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/12 16:39:38 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
int		plus(int a, int b);
int		minus(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putnbr(int nb);
#endif