/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/20 17:02:57 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_ra_rotate_a(t_list **head_a, t_list **head_b, char *instruction)
void	ft_ra_rotate_a(t_list **head_a, char *instruction)
{
	t_list *tmp;
	t_list *last;

	if ((*head_a) == NULL || (*head_a)->next == NULL)
		return ;
		// ft_message_error(head_a, head_b, "ft_ra_rotate_a : 'head_a' doen't exist"); // ! a supprimer
		// ft_message_error(head_a, head_b);
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	last = ft_lstlast(*head_a);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "ra", 2) == 0)
		print_swap("ra");
}

// void	ft_rb_rotate_b(t_list **head_a, t_list **head_b, char *instruction)
void	ft_rb_rotate_b(t_list **head_b, char *instruction)
{
	t_list *tmp;
	t_list *last;

	if ((*head_b) == NULL || (*head_b)->next == NULL)
		return ;
		// ft_message_error(head_a, head_b, "ft_rb_rotate_b : 'head_b' doen't exist"); // ! a supprimer
		// ft_message_error(head_a, head_b);
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	last = ft_lstlast(*head_b);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "rb", 2) == 0)
		print_swap("rb");
}

void	ft_rr_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction)
{
	// if ((*head_a) == NULL || (*head_a)->next == NULL)
	// 	return ;
		// ft_message_error(head_a, head_b, "ft_rr_rotate_a_b : 'head_a' doen't exist"); // ! a supprimer
		// ft_message_error(head_a, head_b);
	// if ((*head_b) == NULL || (*head_b)->next == NULL)
	// 	return ;
		// ft_message_error(head_a, head_b, "ft_rr_rotate_a_b : 'head_b' doen't exist"); // ! a supprimer
		// ft_message_error(head_a, head_b);
	ft_ra_rotate_a(head_a, "rr");
	ft_rb_rotate_b(head_b, "rr");
	if (ft_strncmp(instruction, "rr", 2) == 0)
		print_swap("rr");
}