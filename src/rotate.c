/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/15 17:57:40 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rotate_a(t_list **head)
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
}

void	ft_rb_rotate_b(t_list **head)
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
}

void	ft_rr_rotate_a_b(t_list **head)
{
	if ((*head) == NULL || (*head)->next == NULL)
		ft_message_error("ft_rr_rotate_a_b : 'head' doen't exist");	 // ! a supprimer
		// ft_message_error();
	ft_ra_rotate_a(head);
	ft_rb_rotate_b(head);
}