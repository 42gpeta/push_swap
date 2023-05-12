/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/12 20:05:18 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rotate_a(t_list **head)
{
	t_list *tmp;
	t_list *last;

	if (head == NULL)
		ft_message_error();
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

	if (head == NULL)
		ft_message_error();
	tmp = (*head);
	(*head) = (*head)->next;
	last = ft_lstlast(*head);
	tmp->next = NULL;
	last->next = tmp;
}

void	ft_rr_rotate_a_b(t_list **head)
{
	ft_ra_rotate_a(head);
	ft_rb_rotate_b(head);
}