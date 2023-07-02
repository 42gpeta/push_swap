/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:42:41 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/03 00:33:49 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_ra_rotate_a(t_list **head_a, t_list **head_b, char *instruction)
void	ft_ra_rotate_a(t_list **head_a, char *instruction)
{
	t_list	*tmp;
	t_list	*last;

	if ((*head_a) == NULL || (*head_a)->next == NULL)
		return ;
	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	last = ft_lstlast(*head_a);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "ra", 2) == 0)
		ft_print_swap("ra");
}

// void	ft_rb_rotate_b(t_list **head_a, t_list **head_b, char *instruction)
void	ft_rb_rotate_b(t_list **head_b, char *instruction)
{
	t_list	*tmp;
	t_list	*last;

	if ((*head_b) == NULL || (*head_b)->next == NULL)
		return ;
	tmp = (*head_b);
	(*head_b) = (*head_b)->next;
	last = ft_lstlast(*head_b);
	tmp->next = NULL;
	last->next = tmp;
	if (ft_strncmp(instruction, "rb", 2) == 0)
		ft_print_swap("rb");
}

void	ft_rr_rotate(t_list **head_a, t_list **head_b, char *instruction)
{
	ft_ra_rotate_a(head_a, "rr");
	ft_rb_rotate_b(head_b, "rr");
	if (ft_strncmp(instruction, "rr", 2) == 0)
		ft_print_swap("rr");
}
