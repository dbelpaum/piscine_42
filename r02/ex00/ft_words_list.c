#include "ft.h"

t_words	*ft_create_words(int word_len)
{
	t_words	*list;

	list = malloc(sizeof(t_words));
	if (!list)
		return (NULL);
	list->word = malloc((word_len + 1) * sizeof(char));
	if (!list->word)
		return (NULL);
	list->word = malloc((word_len + 1) * sizeof(char));
	if (!list->word)
		return (NULL);
	list->next = NULL;
	return (list);
}

t_words	*ft_list_last_words(t_words *begin_list)
{
	t_words	*ptr;

	ptr = begin_list;
	if (!ptr)
		return (begin_list);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	list_push_back_w(t_words **begin_list, t_words *list_to_push)
{
	if (!(*begin_list))
		*begin_list = list_to_push;
	else
	{
		list_to_push->next = *begin_list ;
		*begin_list = list_to_push;
	}
}
