/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:56:06 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/16 17:57:30 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_push_a(t_list **head_a, t_list **head_b, char *instruction)
{
	t_list *tmp;
	
	if (!(*head_a) || (*head_a)->next == NULL)
		ft_message_error(head_a, head_b, "ft_pa_push_a : 'head_a' doen't exist");
		// ft_message_error(head_a, head_b);
		
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	if (ft_strncmp(instruction, "pa", 2) == 0)
		print_swap("pa");
}





void	ft_pb_push_b(t_list **head_a, t_list **head_b, char *instruction)
{
	t_list *tmp;
	
	if (!(*head_b))
		ft_message_error(head_a, head_b, "ft_pa_push_b : 'head_b' empty");
		// ft_message_error(head_a, head_b);
	
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	if (ft_strncmp(instruction, "pb", 2) == 0)
		print_swap("pb");
}
