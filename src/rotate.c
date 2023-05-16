/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/16 15:51:11 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rotate_a(t_list **head, char *instruction)
{
	t_list *tmp;
	t_list *last;

	if ((*head) == NULL || (*head)->next == NULL)
		ft_message_error("ft_ra_rotate_a : 'head' doen't exist"); // ! a supprimer
		// ft_message_error();
	tmp = (*head);
	(*head) = (*head)->next;
	last = ft_lstlast(*head);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "ra", 2) == 0)
		print_swap("ra");
}

void	ft_rb_rotate_b(t_list **head, char *instruction)
{
	t_list *tmp;
	t_list *last;

	if ((*head) == NULL || (*head)->next == NULL)
		ft_message_error("ft_rb_rotate_b : 'head' doen't exist"); // ! a supprimer
		// ft_message_error();
	tmp = (*head);
	(*head) = (*head)->next;
	last = ft_lstlast(*head);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "rb", 2) == 0)
		print_swap("rb");
}

void	ft_rr_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction)
{
	if ((*head_a) == NULL || (*head_a)->next == NULL)
		ft_message_error("ft_rr_rotate_a_b : 'head_a' doen't exist");	 // ! a supprimer
		// ft_message_error();
	if ((*head_b) == NULL || (*head_b)->next == NULL)
		ft_message_error("ft_rr_rotate_a_b : 'head_b' doen't exist");	 // ! a supprimer
		// ft_message_error();
	ft_ra_rotate_a(head_a, "rr");
	ft_rb_rotate_b(head_b, "rr");
	if (ft_strncmp(instruction, "rr", 2) == 0)
		print_swap("rr");
}