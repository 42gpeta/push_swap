/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:38:47 by glodi             #+#    #+#             */
/*   Updated: 2023/07/04 21:30:15 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five_node(t_list **head_a, t_list **head_b)
{
	int		size;

	size = ft_lstsize(*head_a);
	while (size > 0)
	{
		if ((*head_a)->index > 2)
		{
			ft_ra_rotate_a(head_a, "ra");
		}
		else
		{
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->next && (*head_b)->index < (*head_b)->next->index)
				ft_rb_rotate_b(head_b, "rb");
		}
		size--;
	}
	ft_sort_tree_node(head_a);
	ft_pa_push_a(head_a, head_b, "pa");
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_sort_four_node(t_list **head_a, t_list **head_b)
{
	int		i;

	i = 0;
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
				break ;
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
	if ((*head_a)->index < (*head_a)->next->index
		&& (*head_a)->next->index < (*head_a)->next->next->index)
		return ;
	else if ((*head_a)->index < (*head_a)->next->index
		&& (*head_a)->next->index > (*head_a)->next->next->index)
		ft_inf_sup(head_a);
	else if ((*head_a)->index > (*head_a)->next->index
		&& (*head_a)->next->index < (*head_a)->next->next->index)
		ft_sup_inf(head_a);
	else if ((*head_a)->index > (*head_a)->next->index
		&& (*head_a)->next->index > (*head_a)->next->next->index)
		ft_sup_sup(head_a);
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
	t_list	*tmp;

	tmp = (*head_a);
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
