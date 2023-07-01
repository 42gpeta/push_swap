/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:35:45 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 18:46:00 by glodi            ###   ########.fr       */
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
				&& (*head_a)->index > (size / 3 * 2)) // si tete_b < 2/3 ET tete_a > 2/3
				ft_rr_rotate_a_b(head_a, head_b, "rr");
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
		ft_leave_three_biggest_in_a(head_a,head_b, size, ft_pre_sort(head_a, head_b, size));
		ft_sort_tree_node(head_a);
	}
	else
	{
		if ((*head_a)->index > (*head_a)->next->index)
			ft_ra_rotate_a(head_a, "ra");
	}
	while ((*head_b))
	{
		ft_nearest_index_for_B_node(head_a, head_b);
		ft_count_rb_and_rrb(head_b);

	/* t_list *cheapest1 = ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b);
		t_list *cheapest2 = ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b);
		t_list *cheapest3 = ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b);
		t_list *cheapest4 = ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b);

		printf("Méthode 1/ node à bouger %d[%d] coup = %d\n", cheapest1->content, cheapest1->index, (cheapest1->ra + cheapest1->rb));
		printf("Méthode 2/ node à bouger %d[%d] coup = %d\n", cheapest2->content, cheapest2->index, (cheapest2->ra + cheapest2->rb));
		printf("Méthode 3/ node à bouger %d[%d] coup = %d\n", cheapest3->content, cheapest3->index, (cheapest3->ra + cheapest3->rb));
		printf("Méthode 4/ node à bouger %d[%d] coup = %d\n", cheapest4->content, cheapest4->index, (cheapest4->ra + cheapest4->rb)); */

		ft_execute_best_combination(head_a, head_b, ft_choose_best_combination(head_a, head_b));
	}
	ft_put_index_one_on_top(head_a);
}

void	ft_leave_three_biggest_in_a(t_list **head_a, t_list **head_b, int max_index, int size)
{
	while(size > 0)
	{
		if ((*head_a)->index > (max_index - 3))
			ft_ra_rotate_a(head_a,"ra");
		else
			ft_pb_push_b(head_a,head_b,"pb");
		size--;
	}
}

void	ft_put_index_one_on_top(t_list **head_a)
{
	t_list *tmp_a;
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
	// printf("ra | rra :\n%d | %d\n", ra, rra); // ! a supprimer
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
