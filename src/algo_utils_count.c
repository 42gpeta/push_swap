/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:36:39 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 18:40:54 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Save ra and rra on node B
void	ft_nearest_index_for_B_node(t_list **head_a, t_list **head_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int		nearest_index;
	int		i;

	tmp_b = *head_b;
	while (tmp_b)
	{
		tmp_a = *head_a;
		i = 0;
		nearest_index = ft_lstsize(*head_a) + ft_lstsize(*head_b);
		// printf("\e[103;5mnodeB : %d\e[0m\n", tmp_b->index); // ! a supprimer
		// printf("nearest : %d\n", nearest_index); // ! a supprimer
		while (tmp_a)
		{
			// printf("tmp_a index : %d\n --> %d > %d = %d\n  --> %d < %d = %d\n",tmp_a->index, tmp_a->index, tmp_b->index, (tmp_a->index > tmp_b->index), tmp_a->index, nearest_index, (tmp_a->index < nearest_index)); // ! a supprimer
			if (tmp_a->index > tmp_b->index && tmp_a->index < nearest_index)
			{
				nearest_index = tmp_a->index;
				tmp_b->ra = i;
				tmp_b->rra = ft_lstsize(*head_a) - tmp_b->ra;
				// printf("  \e[31mnew_rearest = %d\n -> tmp_b->ra = %i\e[0m\n", nearest_index, i); // ! a supprimer
			}
			tmp_a = tmp_a->next;
			i++;
		}
		tmp_b = tmp_b->next;
	}
}

void	ft_count_rb_and_rrb(t_list **head_b)
{
	int	i;
	t_list *tmp;

	i = 0;
	tmp = *head_b;
	while (tmp)
	{
		tmp->rb = i;
		tmp->rrb = ft_lstsize(*head_b) - tmp->rb;
		tmp = tmp->next;
		i++;
	}
}
