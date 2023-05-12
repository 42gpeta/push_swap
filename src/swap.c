/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/12 18:59:42 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **head)
{
	t_list	*tmp;
	
	if (!head)
		return;
	tmp = (*head); // sauvegarde du head
	(*head) = (*head)->next; // nouveau head c'est le 2e node
	tmp->next = (*head)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	
}