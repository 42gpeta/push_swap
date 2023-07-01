/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 19:05:07 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_sa_swap_a(t_list **head_a, t_list **head_b, char *instruction)
void	ft_sa_swap_a(t_list **head_a, char *instruction)
{
	t_list	*tmp;
	
	if (!(*head_a) || (*head_a)->next == NULL)
		return ;
		// ft_message_error(head_a, head_b, "ft_sa_swap_a : 'head' doesn't exist"); // ! supprimer
		// ft_message_error(head_a, head_b);
	tmp = (*head_a); // sauvegarde du head
	(*head_a) = (*head_a)->next; // nouveau head c'est le 2e node
	tmp->next = (*head_a)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head_a)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	if (ft_strncmp(instruction,"sa", 2) == 0)
		ft_print_swap("sa");
}

// void	ft_sb_swap_b(t_list **head_a, t_list **head_b, char *instruction)
void	ft_sb_swap_b(t_list **head_b, char *instruction)
{
	t_list	*tmp;
	
	if (!(*head_b) || (*head_b)->next == NULL)
		return ;
		// ft_message_error(head_a, head_b, "ft_sb_swap_b : 'head' doesn't exist"); // ! supprimer
		// ft_message_error(head_a, head_b);
	tmp = (*head_b); // sauvegarde du head
	(*head_b) = (*head_b)->next; // nouveau head c'est le 2e node
	tmp->next = (*head_b)->next; // l'ancien head->next avec le 3e node pour ne pas perdre le pointeur du 3e node
	(*head_b)->next = tmp; // je lie le nouveau head au "nouveau" 2e node
	if (ft_strncmp(instruction,"sb", 2) == 0)
		ft_print_swap("sb");
}

// void	ft_ss_swap_a_b(char *instruction)
void	ft_ss_swap_a_b(t_list **head_a, t_list **head_b, char *instruction)
{
	ft_sa_swap_a(head_a, "ss");
	ft_sb_swap_b(head_b, "ss");
	if (ft_strncmp(instruction,"ss", 2) == 0)
		ft_print_swap("ss");
}