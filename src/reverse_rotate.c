/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:50:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/13 17:07:18 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_reverse_rotate_a(t_list **list) // ? v1
{
	t_list *tmp;
	t_list *last_node;
	int		i;

	i = 0;
	
	// tmp = ft_lstlast(*list);
	// tmp->next = (*list);
	tmp = (*list);
	last_node = tmp;
	
	while ((*list)->next->next != NULL)
	{	
		(*list) = (*list)->next;
		i++;
	}
	// (*list)->next->next = tmp;
	// (*list)->next = NULL;
	
	
	// while (last_node->next->next != NULL)
	// {	
	// 	last_node = last_node->next;
	// 	i++;
	// }
	// last_node->next = NULL;
	
	
	// (*list) = (*list)->next;
	// (*list)->next = NULL;
	
	// last_node = ft_lstlast(*list);
	// last_node->next = NULL;

	
	// (*list) = last_node;
	// (*list) = tmp;
	// (*list) = tmp->next->next;
	// (*list) = ft_lstlast(*list);	
	printf("ft_rra_reverse_rotate_a list content  : %d\n", (*list)->content);
	printf("ft_rra_reverse_rotate_a list next     : %d\n", (*list)->next->content);
	printf("ft_rra_reverse_rotate_a list next next: %p\n", (*list)->next->next);
	printf("ft_rra_reverse_rotate_a content : %d\n", tmp->content);
	printf("ft_rra_reverse_rotate_a    next : %p\n", tmp->next);
	printf("ft_rra_reverse_rotate_a : %d\n", i);
	
	// last_node = ft_lstlast(*list);
	// // ft_lstadd_front(list, last_node);
	// last_node->next = NULL;
		
		
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

// void	ft_rrb_reverse_rotate_b(t_list **list)
// {
	
// }

// void	ft_rrr_reverse_rotate_a_b(t_list **list)
// {
	
// }