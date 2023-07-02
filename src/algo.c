/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:35:45 by glodi             #+#    #+#             */
/*   Updated: 2023/07/03 00:33:49 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pre_sort(t_list **head_a, t_list **head_b, int size)
{
	int		i;

	i = 0;
	while (*head_a && i < size)
	{
		if ((*head_a)->index <= (size / 3 * 2))
		{
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->index <= ((size / 3 * 2) / 2)
				&& (*head_a)->index > (size / 3 * 2))
				ft_rr_rotate(head_a, head_b, "rr");
			else if ((*head_b)->index <= ((size / 3 * 2) / 2))
				ft_rb_rotate_b(head_b, "rb");
		}
		else
			ft_ra_rotate_a(head_a, "ra");
		i++;
	}
	size = ft_lstsize(*head_a);
	return (size);
}

void	ft_sort(t_list **head_a, t_list **head_b)
{
	int		size;

	size = ft_lstsize(*head_a);
	ft_pre_sort(head_a, head_b, size);
	if (size != 6)
	{
		ft_leave_3_biggest(head_a, head_b, size,
			ft_pre_sort(head_a, head_b, size));
		ft_sort_tree_node(head_a);
	}
	else
	{
		if ((*head_a)->index > (*head_a)->next->index)
			ft_ra_rotate_a(head_a, "ra");
	}
	while ((*head_b))
	{
		ft_nearest_index_for_b_node(head_a, head_b);
		ft_count_rb_and_rrb(head_b);
		ft_exe_best_combination(head_a, head_b,
			ft_choose_best_combination(head_a, head_b));
	}
	ft_put_index_one_on_top(head_a);
}
/* Leave 3 biggest in node A */
void	ft_leave_3_biggest(t_list **h_a, t_list **h_b, int max_i, int size)
{
	while (size > 0)
	{
		if ((*h_a)->index > (max_i - 3))
			ft_ra_rotate_a(h_a, "ra");
		else
			ft_pb_push_b(h_a, h_b, "pb");
		size--;
	}
}

void	ft_put_index_one_on_top(t_list **head_a)
{
	t_list	*tmp_a;
	int		ra;
	int		rra;

	tmp_a = *head_a;
	ra = 0;
	while (tmp_a->index != 1)
	{
		tmp_a = tmp_a->next;
		ra++;
	}
	rra = ft_lstsize(*head_a) - ra;
	if (ra < rra)
	{
		while ((*head_a)->index != 1)
			ft_ra_rotate_a(head_a, "ra");
	}
	else
	{
		while ((*head_a)->index != 1)
			ft_rra_reverse_rotate_a(head_a, "rra");
	}
}
