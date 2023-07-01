/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:38:47 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 19:04:56 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_node(t_list **head_a, t_list **head_b) // ! non terminée ; ? v2
{
	int i;
	int size;
	int max_index;

	i = 0;
	size = ft_lstsize(*head_a);
	max_index = 5;
	while(size > 0)
	{

		if ((*head_a)->index > 2)
		{
			ft_ra_rotate_a(head_a,"ra");
		}
		else
			ft_pb_push_b(head_a,head_b,"pb");
		size--;
	}	
	ft_sort_tree_node(head_a);
	ft_pa_push_a(head_a, head_b, "pa");
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_sort_four_node(t_list **head_a, t_list **head_b) // ? v2
{
	int i = 0;
	
	if (ft_lstsize(*head_a) == 3)
		ft_sort_tree_node(head_a);
	else if (ft_lstsize(*head_a) > 3)
	{
		ft_pb_push_b(head_a, head_b, "pb");
		ft_sort_tree_node(head_a);
		while ((*head_a) && i < ft_lstsize(*head_a))
		{
			if ((*head_a)->index == (*head_b)->index + 1)
			{
				break;
			}
			else
				ft_ra_rotate_a(head_a, "ra");
			i++;
		}
		ft_pa_push_a(head_a, head_b, "pa");
		while ((*head_a)->index != 1)
			ft_ra_rotate_a(head_a, "ra");
	}
}

void	ft_sort_tree_node(t_list **head_a)
{
	// 1 2 3
	if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
		return ;
	// 1 3 2 et 2 3 1
	else if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index)
		{
			ft_sa_swap_a(head_a, "sa");
			ft_ra_rotate_a(head_a, "ra");
		}
		else if ((*head_a)->index > (*head_a)->next->next->index)
			ft_rra_reverse_rotate_a(head_a, "rra");
	}
	// 2 1 3 et 3 1 2
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index)
			ft_sa_swap_a(head_a, "sa");
		else if ((*head_a)->index > (*head_a)->next->next->index)
			ft_ra_rotate_a(head_a, "ra");
	}	
	// 3 2 1
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
	{
		ft_sa_swap_a(head_a, "sa");
		ft_rra_reverse_rotate_a(head_a, "rra");
	}
}

void	ft_sort_two_node(t_list **head_a)
{
	if ((*head_a)->index > (*head_a)->next->index)
		ft_sa_swap_a(head_a, "sa");
	else
		return ;
}

int	ft_is_sorted(t_list **head_a)
{
	t_list *tmp;

	tmp = (*head_a);
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
