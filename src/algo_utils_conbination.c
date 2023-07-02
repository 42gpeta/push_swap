/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_conbination.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:35:25 by glodi             #+#    #+#             */
/*   Updated: 2023/07/03 00:31:45 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_choose_best_combination(t_list **head_a, t_list **head_b)
{
	int		cheapest[4];
	int		i;
	int		index_w_cheapest_shoot;
	int		smallest_sum;

	cheapest[0] = ft_find_node_w_cheapest_ra_rb(head_a, head_b)->ra 
		+ ft_find_node_w_cheapest_ra_rb(head_a, head_b)->rb;
	cheapest[1] = ft_find_node_w_cheapest_ra_rrb(head_a, head_b)->ra 
		+ ft_find_node_w_cheapest_ra_rrb(head_a, head_b)->rrb;
	cheapest[2] = ft_find_node_w_cheapest_rra_rb(head_a, head_b)->rra 
		+ ft_find_node_w_cheapest_rra_rb(head_a, head_b)->rb;
	cheapest[3] = ft_find_node_w_cheapest_rra_rrb(head_a, head_b)->rra 
		+ ft_find_node_w_cheapest_rra_rrb(head_a, head_b)->rrb;
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

void	ft_exe_best_combination(t_list **head_a, t_list **head_b, int index)
{
	if (index == 0)
		ft_exe_ra_rb(head_a, head_b,
			ft_find_node_w_cheapest_ra_rb(head_a, head_b));
	else if (index == 1)
		ft_exe_ra_rrb(head_a, head_b,
			ft_find_node_w_cheapest_ra_rrb(head_a, head_b));
	else if (index == 2)
		ft_exe_rra_rb(head_a, head_b,
			ft_find_node_w_cheapest_rra_rb(head_a, head_b));
	else if (index == 3)
		ft_exe_rra_rrb(head_a, head_b,
			ft_find_node_w_cheapest_rra_rrb(head_a, head_b));
}
