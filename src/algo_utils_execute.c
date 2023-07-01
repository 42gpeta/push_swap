/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:37:31 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 18:41:58 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute_ra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int ra;
	int	rb;

	ra = nearest_index->ra;
	rb = nearest_index->rb;
	while (ra > 0 && rb > 0)
	{
		ft_rr_rotate_a_b(head_a, head_b, "rr");
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		ra--;
	}
	while (rb > 0)
	{
		ft_rb_rotate_b(head_b, "rb");
		rb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_ra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int ra;
	int	rrb;

	ra = nearest_index->ra;
	rrb = nearest_index->rrb;
	while (ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		ra--;
	}
	while (rrb > 0)
	{
		ft_rrb_reverse_rotate_b(head_b, "rrb");
		rrb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_rra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int rra;
	int	rb;

	rra = nearest_index->rra;
	rb = nearest_index->rb;
	while (rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		rra--;
	}
	while (rb > 0)
	{
		ft_rb_rotate_b(head_b, "rb");
		rb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_rra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int rra;
	int	rrb;

	rra = nearest_index->rra;
	rrb = nearest_index->rrb;
	while (rra > 0 && rrb > 0)
	{
		ft_rrr_reverse_rotate_a_b(head_a, head_b, "rrr");
		rra--;
		rrb--;
	}
	while (rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		rra--;
	}
	while (rrb > 0)
	{
		ft_rrb_reverse_rotate_b(head_b, "rrb");
		rrb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}
