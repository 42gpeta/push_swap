/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:50:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/15 17:57:57 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_reverse_rotate_a(t_list **head) // ? v1
{
	t_list *tmp;
	t_list *second_last;
	
	if (!(*head) || (*head)->next == NULL)
		ft_message_error("ft_rra_reverse_rotate_a : 'head' or 'head->next' doesn't exist");  // ! a supprimer
		// ft_message_error();
	
	tmp = (*head);
	second_last = NULL;
	while (tmp->next != NULL)
	{	
		second_last = tmp;	
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->next = (*head);
	(*head) = tmp;
}

// void	ft_rra_reverse_rotate_a(t_list **list) // ? v2
// {
// 	t_list *tmp;
// 	// t_list **last_node;
// 	int		i;

// 	i = 0;
	
// 	// tmp = ft_lstlast(*list);
// 	// tmp->next = (*list);
// 	tmp = (*list);
// 	while ((*list)->next->next != NULL)
// 	{	
// 		(*list) = (*list)->next;
// 		i++;
// 	}
// 	(*list)->next = NULL;
// 	(*list) = tmp;
// 	// (*list) = tmp->next->next;
// 	// (*list) = ft_lstlast(*list);	
// 	// (*last_node)->next = NULL;
// 	printf("ft_rra_reverse_rotate_a : %d\n", tmp->content);
// 	printf("ft_rra_reverse_rotate_a : %d\n", i);
	
// 	// last_node = ft_lstlast(*list);
// 	// // ft_lstadd_front(list, last_node);
// 	// last_node->next = NULL;
		
		
// }

void	ft_rrb_reverse_rotate_b(t_list **head)
{
	t_list *tmp;
	t_list *second_last;
	
	if (!(*head) || (*head)->next == NULL)
		ft_message_error("ft_rrb_reverse_rotate_b : 'head' or 'head->next' doesn't exist");  // ! a supprimer
		// ft_message_error();
	
	tmp = (*head);
	second_last = NULL;
	while (tmp->next != NULL)
	{	
		second_last = tmp;	
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->next = (*head);
	(*head) = tmp;	
}

void	ft_rrr_reverse_rotate_a_b(t_list **head)
{
	if (!(*head) || (*head)->next == NULL)
		ft_message_error("ft_rrr_reverse_rotate_a_b : 'head' or 'head->next' doesn't exist");  // ! a supprimer
		// ft_message_error();
	ft_rra_reverse_rotate_a(head);
	ft_rrb_reverse_rotate_b(head);
}