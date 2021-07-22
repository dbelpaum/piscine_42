/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:04:19 by dbelpaum          #+#    #+#             */
/*   Updated: 2021/07/17 20:17:39 by dbelpaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_process_file(int fd)
{
	char	buffer[1024];
	int		length;
	char	*content;

	content = (char *)malloc(sizeof(char) * 1);
	if (!content)
		return (NULL);
	content[0] = 0;
	length = 1;
	while (length > 0)
	{
		length = read(fd, buffer, 1024);
		if (length > 0)
		{
			content = ft_strncat_malloc(content, buffer, length);
			if (!content)
				return (NULL);
		}
	}
	return (content);
}
