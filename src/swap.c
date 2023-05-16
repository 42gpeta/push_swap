/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/16 15:37:31 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap_a(t_list **head, char *instruction)
{
	t_list	*tmp;
	
	if (!(*head) || (*head)->next == NULL)
		ft_message_error("ft_sa_swap_a : 'head' doesn't exist"); // ! supprimer
		// ft_message_error();
	tmp = (*head); // sauvegarde du head
	(*head) = (*head)->next; // nouveau head c'est le 2e node
	tmp->next = (*head)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	if (ft_strncmp(instruction,"sa", 2) == 0)
		print_swap("sa");
}

void	ft_sb_swap_b(t_list **head, char *instruction)
{
	t_list	*tmp;
	
	if (!(*head) || (*head)->next == NULL)
		ft_message_error("ft_sb_swap_b : 'head' doesn't exist"); // ! supprimer
		// ft_message_error();
	tmp = (*head); // sauvegarde du head
	(*head) = (*head)->next; // nouveau head c'est le 2e node
	tmp->next = (*head)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	if (ft_strncmp(instruction,"sb", 2) == 0)
		print_swap("sb");
}

void	ft_ss_swap_a_b(t_list **head_a, t_list **head_b, char *instruction)
{
	if (!(*head_a) || (*head_a)->next  == NULL)
		ft_message_error("ft_ss_swap_a_b : 'head_a' doesn't exist"); // ! supprimer
		// ft_message_error();
	if (!(*head_b) || (*head_b)->next  == NULL)
		ft_message_error("ft_ss_swap_a_b : 'head_b' doesn't exist"); // ! supprimer
		// ft_message_error();
	ft_sa_swap_a(head_a, "ss");
	ft_sb_swap_b(head_b, "ss");
	if (ft_strncmp(instruction,"ss", 2) == 0)
		print_swap("ss");
}