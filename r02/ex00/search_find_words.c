#include "ft.h"

t_words	*search(char *str)
{
	t_words	*elem;

	elem = ft_create_words(ft_strlen(str));
	if (elem == NULL)
		return (NULL);
	elem->word = str;
	return (elem);
}

char	*ft_list_find_by_size(t_list *begin_list, int size_ref)
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr->next)
	{
		if (ptr->size == size_ref)
			return (ptr->word);
		ptr = ptr->next;
	}
	if (ptr->size == size_ref)
		return (ptr->word);
	return (0);
}

char	*ft_list_find_by_number(t_list *begin_list, char *number_ref)
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr->next)
	{
		if (ft_strcmp(ptr->number, number_ref) == 0)
			return (ptr->word);
		ptr = ptr->next;
	}
	if (ft_strcmp(ptr->number, number_ref) == 0)
		return (ptr->word);
	return (0);
}
