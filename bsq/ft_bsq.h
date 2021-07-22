/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:22:42 by malouvar          #+#    #+#             */
/*   Updated: 2021/07/22 11:15:56 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFERSIZE 1024

typedef struct s_map
{
	int		lines;
	int		length;
	char	vide;
	char	plein;
	char	obs;
	int		**map;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
char	*ft_strncat_malloc(char *old, char *src, int n);
char	*process_file(int fd, int fileSize);
char	*process_file_stdin(int fd);
int		ft_first_line(char *str_map, t_map *map);
t_map	*ft_map(char *file);
int		ft_strlen(char *str);
int		ft_antoi(char *str, int n);
int		**ft_split_number(char *str, char *charset, char chrs[2]);
int		**str_to_matrix(char *str, char obst, char empty);
void	ft_solve(t_map *map);
void	ft_putchar(char c);
int		ft_get_line_length(char *str);
int		ft_map_ok(char *str_map, t_map *map);
#endif
