/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:56:06 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 19:01:21 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_push_b(t_list **head_a, t_list **head_b, char *instruction)
{
	t_list *tmp;
	
	if (!(*head_a))
		return ;
		// ft_message_error(head_a, head_b, "ft_pb_push_b : 'head_a' empty");
		// ft_message_error(head_a, head_b);
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	if (ft_strncmp(instruction, "pb", 2) == 0)
		ft_print_swap("pb");
}

void	ft_pa_push_a(t_list **head_a, t_list **head_b, char *instruction)
{
	t_list *tmp;
	
	if (!(*head_b))
		return ;
		// ft_message_error(head_a, head_b, "ft_pa_push_a : 'head_b' empty");
		// ft_message_error(head_a, head_b);
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	if (ft_strncmp(instruction, "pa", 2) == 0)
		ft_print_swap("pa");
}
