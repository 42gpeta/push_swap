/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:02:25 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/02 23:24:39 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* List creation */
t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

/* Add new node in front of the list (far of the first) */
void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (*list)
		node->next = *list;
	*list = node;
}

/* Add the last node with ->next = NULL */
int	ft_lstadd_back(t_list **list, t_list *last_node)
{
	t_list	*tmp;

	if (!last_node)
		return (-1);
	if (!*list)
	{
		*list = last_node;
		return (-1);
	}
	tmp = ft_lstlast(*list);
	tmp->next = last_node;
	return (0);
}

/* Go to the last node */
t_list	*ft_lstlast(t_list *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_lstsize(t_list *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
