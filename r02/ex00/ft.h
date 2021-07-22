/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelpaum <dbelpaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:28:59 by ctchen            #+#    #+#             */
/*   Updated: 2021/07/18 20:26:40 by tbrowang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
char	*ft_process_file(int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
char	*ft_strncat_malloc(char *dest, char *src, int n);
int		is_number(char c);
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(char c);
char	*ft_strndup(const char *s, int n);
char	*ft_strndup_rev(char *src, int n);
char	*ft_strcat(char *dest, char *src);
typedef struct s_list
{
	char			*number;
	char			*word;
	int				size;
	struct s_list	*next;
}t_list;
typedef struct s_words
{
	char			*word;
	struct s_words	*next;
}t_words;
t_list	*ft_file_to_list(int fd);
void	ft_list_push_back(t_list **begin_list, t_list *list_to_push);
t_list	*ft_create_elem(int nb_len, int word_len);
t_list	*ft_list_last(t_list *begin_list);
void	list_push_back_w(t_words **begin_list, t_words *list_to_push);
t_words	*ft_create_words(int word_len);
t_words	*ft_list_last_words(t_words *begin_list);
t_words	*build_string(char *input, t_list *dico);
char	*ft_listjoin(t_words *begin_list);
char	*ft_cut(int start, int end, char *str);
char	*ft_list_find_by_number(t_list *begin_list, char *number_ref);
char	*ft_list_find_by_size(t_list *begin_list, int size_ref);
t_words	*search(char *str);
#endif
