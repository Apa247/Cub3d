#include "libft.h"

t_list	*ft_lstcopy(t_list *list, t_list *limit)
{
	t_list	*node;
	t_list	*newlist;

	if (list == NULL)
		return (NULL);
	node = list;
	newlist = NULL;
	while (node != limit)
	{
		ft_lstinsert(&newlist, node->content, BACK);
		node = node->next;
	}
	return (NULL);
}
