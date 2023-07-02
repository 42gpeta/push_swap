/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:50:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/03 00:33:21 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_reverse_rotate_a(t_list **head_a, char *instruction)
{
	t_list	*tmp;
	t_list	*second_last;

	if (!(*head_a) || (*head_a)->next == NULL)
		return ;
	tmp = (*head_a);
	second_last = NULL;
	while (tmp->next != NULL)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->next = (*head_a);
	(*head_a) = tmp;
	if (ft_strncmp(instruction, "rra", 3) == 0)
		ft_print_swap("rra");
}

void	ft_rrb_reverse_rotate_b(t_list **head_b, char *instruction)
{
	t_list	*tmp;
	t_list	*second_last;

	if (!(*head_b) || (*head_b)->next == NULL)
		return ;
	tmp = (*head_b);
	second_last = NULL;
	while (tmp->next != NULL)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->next = (*head_b);
	(*head_b) = tmp;
	if (ft_strncmp(instruction, "rrb", 3) == 0)
		ft_print_swap("rrb");
}

void	ft_rrr_reverse_rotate(t_list **h_a, t_list **h_b, char *instruction)
{
	ft_rra_reverse_rotate_a(h_a, "rrr");
	ft_rrb_reverse_rotate_b(h_b, "rrr");
	if (ft_strncmp(instruction, "rrr", 3) == 0)
		ft_print_swap("rrr");
}
