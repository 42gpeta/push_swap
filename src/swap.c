/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/12 20:04:17 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap_a(t_list **head)
{
	t_list	*tmp;
	
	if (!head)
		ft_message_error();
	tmp = (*head); // sauvegarde du head
	(*head) = (*head)->next; // nouveau head c'est le 2e node
	tmp->next = (*head)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	
}

void	ft_sb_swap_b(t_list **head)
{
	t_list	*tmp;
	
	if (!head)
		ft_message_error();
	tmp = (*head); // sauvegarde du head
	(*head) = (*head)->next; // nouveau head c'est le 2e node
	tmp->next = (*head)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	
}

void	ft_ss_swap_a_b(t_list **head)
{
	ft_sa_swap_a(head);
}