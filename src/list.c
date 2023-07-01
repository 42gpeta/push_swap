/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:02:25 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 18:21:09 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



/* Création de la liste */
t_list	*ft_lstnew(int content)
{
	// static int i = 5;
	t_list	*head;

	// i--;
	// if (i == 0)
	// 	return (NULL);
	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}

/* Ajout du 2ème élément de la liste (très loin du NULL) */
void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (*list)
		node->next = *list;
	*list = node;
}

/* Ajout du dernier node (il contient le ABC->next = NULL) */
// void	ft_lstadd_back(t_list **list, t_list *last_node) // ? v1
// {
// 	// (*list)->index = 1;
	
// 	t_list	*tmp;

// 	if (!last_node)
// 		return ;
// 	if (!*list)
// 	{
// 		*list = last_node;
// 		return ;
// 	}
// 	tmp = ft_lstlast(*list);
// 	tmp->next = last_node;
// 	// (*list)->index = (*list)->index + 1;
// }

int	ft_lstadd_back(t_list **list, t_list *last_node) // ? v2
{
	// (*list)->index = 1;
	
	t_list	*tmp;

	if (!last_node)
		return(-1);
	if (!*list)
	{
		*list = last_node;
		return(-1);
	}
	tmp = ft_lstlast(*list);
	tmp->next = last_node;
	// (*list)->index = (*list)->index + 1;
	return(0);
}

/* Permet d'aller à la fin de la liste */
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