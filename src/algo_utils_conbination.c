/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_conbination.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:35:25 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 18:40:35 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_choose_best_combination(t_list **head_a, t_list **head_b)
{
	int cheapest[4];
	int i;
	int index_w_cheapest_shoot;
	int smallest_sum;

	cheapest[0] = ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->ra + ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->rb;
	// printf("TOTAL CHEAPEST 1 = %d\n", cheapest[0]); // ! a supprimer
	cheapest[1] = ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b)->ra + ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b)->rrb;
	// printf("TOTAL CHEAPEST 2 = %d\n", cheapest[1]); // ! a supprimer
	cheapest[2] = ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b)->rra + ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b)->rb;
	// printf("TOTAL CHEAPEST 3 = %d\n", cheapest[2]); // ! a supprimer
	cheapest[3] = ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b)->rra + ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b)->rrb;
	// printf("TOTAL CHEAPEST 4 = %d\n", cheapest[3]); // ! a supprimer
	
	i = 0;
	smallest_sum = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (i < 4)
	{
		if (cheapest[i] < smallest_sum)
		{	
			index_w_cheapest_shoot = i;
			smallest_sum = cheapest[i];
		}
		i++;

	}
	return (index_w_cheapest_shoot);
}

void	ft_execute_best_combination(t_list **head_a, t_list **head_b, int index)
{
	if (index == 0)
		ft_execute_ra_rb(head_a, head_b, ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b));
	else if (index == 1)
		ft_execute_ra_rrb(head_a, head_b, ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b));
	else if (index == 2)
		ft_execute_rra_rb(head_a, head_b, ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b));
	else if (index == 3)
		ft_execute_rra_rrb(head_a, head_b, ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b));
}