/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:02:25 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/16 18:22:19 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Création d'un node */
t_list	*ft_create_node(int data)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list) * 1);
	if (!cell)
		return (NULL);
	cell->content = data;
	cell->next = NULL;

	return (cell);
}

/* Création de la liste */
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

/* Ajout du 2ème élément de la liste (très loin du NULL) */
void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (*list)
		node->next = *list;
	*list = node;
}

/* Ajout du dernier node (il contient le ABC->next = NULL) */
void	ft_lstadd_back(t_list **list, t_list *last_node)
{
	// (*list)->index = 1;
	
	t_list	*tmp;

	if (!last_node)
		return ;
	if (!*list)
	{
		*list = last_node;
		return ;
	}
	tmp = ft_lstlast(*list);
	tmp->next = last_node;
	// (*list)->index = (*list)->index + 1;
}

/* Permet d'aller à la fin de la liste */
t_list	*ft_lstlast(t_list *node)
{
	while (node && node->next != NULL)
		node = node->next;
	return (node);
}

// void	ft_free(t_list *head_a)
void	ft_free(t_list *head_a, t_list *head_b)
{
	t_list *tmp_a;
	t_list *tmp_b;

	if (head_a == NULL)
		return ;
	tmp_a = head_a->next;
	free(head_a);
	while (tmp_a)
	{
		head_a = tmp_a;
		tmp_a = head_a->next;
		free(head_a);
	}
	
	if (head_b == NULL)
		return ;
	// if (head_b)
	// 	if (*head_b)
	// 	{
	// 		free(*head_b);
	// 		return ;
	// 	}
	tmp_b = head_b->next;
	free(head_b);
	while (tmp_b)
	{
		head_b = tmp_b;
		tmp_b = head_b->next;
		free(head_b);
	}
}