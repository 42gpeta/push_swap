/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 23:41:44 by glodi             #+#    #+#             */
/*   Updated: 2023/07/02 23:53:15 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 1 3 2 et 2 3 1 */
void	ft_inf_sup(t_list **head_a)
{
	if ((*head_a)->index < (*head_a)->next->next->index)
	{
		ft_sa_swap_a(head_a, "sa");
		ft_ra_rotate_a(head_a, "ra");
	}
	else if ((*head_a)->index > (*head_a)->next->next->index)
		ft_rra_reverse_rotate_a(head_a, "rra");
}

/* 2 1 3 et 3 1 2 */
void	ft_sup_inf(t_list **head_a)
{
	if ((*head_a)->index < (*head_a)->next->next->index)
		ft_sa_swap_a(head_a, "sa");
	else if ((*head_a)->index > (*head_a)->next->next->index)
		ft_ra_rotate_a(head_a, "ra");
}

/* 3 2 1 */
void	ft_sup_sup(t_list **head_a)
{
	ft_sa_swap_a(head_a, "sa");
	ft_rra_reverse_rotate_a(head_a, "rra");
}
