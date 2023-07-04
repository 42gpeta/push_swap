/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_find_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:37:50 by glodi             #+#    #+#             */
/*   Updated: 2023/07/04 14:57:49 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the nearest upper index of all node in B with cheapest shoot (ra rb)
t_list	*ft_find_node_w_cheapest_ra_rb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_b;
	t_list	*cheapest;
	int		ra_rb;

	tmp_b = *head_b;
	ra_rb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->ra + tmp_b->rb) < ra_rb)
		{
			cheapest = tmp_b;
			ra_rb = tmp_b->ra + tmp_b->rb;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}

// Find the nearest upper index of all node in B with cheapest shoot (ra rrb)
t_list	*ft_find_node_w_cheapest_ra_rrb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_b;
	t_list	*cheapest;
	int		ra_rrb;

	tmp_b = *head_b;
	ra_rrb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->ra + tmp_b->rrb) < ra_rrb)
		{
			cheapest = tmp_b;
			ra_rrb = tmp_b->ra + tmp_b->rrb;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}

// Find the nearest upper index of all node in B with cheapest shoot (rra rb)
t_list	*ft_find_node_w_cheapest_rra_rb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_b;
	t_list	*cheapest;
	int		rra_rb;

	tmp_b = *head_b;
	rra_rb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->rra + tmp_b->rb) < rra_rb)
		{
			cheapest = tmp_b;
			rra_rb = tmp_b->rra + tmp_b->rb;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}

// Find the nearest upper index of all node in B with cheapest shoot (rra rrb)
t_list	*ft_find_node_w_cheapest_rra_rrb(t_list **head_a, t_list **head_b)
{
	t_list	*tmp_b;
	t_list	*cheapest;
	int		rra_rrb;

	tmp_b = *head_b;
	cheapest = tmp_b;
	rra_rrb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->rra + tmp_b->rrb) < rra_rrb)
		{
			cheapest = tmp_b;
			rra_rrb = tmp_b->rra + tmp_b->rrb;
		}
		tmp_b = tmp_b->next;
	}
	return (cheapest);
}
