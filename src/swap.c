/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/03 00:41:44 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap_a(t_list **head_a, char *instruction)
{
	t_list	*tmp;

	if (!(*head_a) || (*head_a)->next == NULL)
		return ;
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	tmp->next = (*head_a)->next;
	(*head_a)->next = tmp;
	if (ft_strncmp(instruction, "sa", 2) == 0)
		ft_print_swap("sa");
}

void	ft_sb_swap_b(t_list **head_b, char *instruction)
{
	t_list	*tmp;

	if (!(*head_b) || (*head_b)->next == NULL)
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	tmp->next = (*head_b)->next;
	(*head_b)->next = tmp;
	if (ft_strncmp(instruction, "sb", 2) == 0)
		ft_print_swap("sb");
}

void	ft_ss_swap(t_list **head_a, t_list **head_b, char *instruction)
{
	ft_sa_swap_a(head_a, "ss");
	ft_sb_swap_b(head_b, "ss");
	if (ft_strncmp(instruction, "ss", 2) == 0)
		ft_print_swap("ss");
}
