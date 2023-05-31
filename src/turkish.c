/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:13:59 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/31 15:59:37 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_a_min(t_list **head_a, t_list **head_b)
{
	int i;

	if (!(*head_a))
		ft_message_error(head_a, head_b, "ft_list_a_min : head doen't exist.");
		// ft_message_error(head_a, head_b);
	i = (*head_a)->index;
	
	while ((*head_a))
	{
		if (i > (*head_a)->index)
			i = (*head_a)->index;
		(*head_a) = (*head_a)->next;
	}
	printf("\nLIST A INDEX MIN = %d\n", i); // ! a supprimer

	return (i);
}

int	ft_list_a_max(t_list **head_a, t_list **head_b)
{
	int i;

	if (!(*head_a))
		ft_message_error(head_a, head_b, "ft_list_a_max : head doen't exist.");
		// ft_message_error(head_a, head_b);
	i = (*head_a)->index;
	
	while ((*head_a))
	{
		if (i < (*head_a)->index)
			i = (*head_a)->index;
		(*head_a) = (*head_a)->next;
	}
	printf("\nLIST A INDEX MAX = %d\n", i); // ! a supprimer

	return (i);
}

int	ft_list_b_min(t_list **head_a, t_list **head_b)
{
	int i;

	if (!(*head_b))
		ft_message_error(head_a, head_b, "ft_list_b_min : head doen't exist.");
		// ft_message_error(head_a, head_b);
	i = (*head_b)->index;
	
	while ((*head_b))
	{
		if (i > (*head_b)->index)
			i = (*head_b)->index;
		(*head_b) = (*head_b)->next;
	}
	printf("\nLIST B INDEX MIN = %d\n", i); // ! a supprimer

	return (i);
}

int	ft_list_b_max(t_list **head_a, t_list **head_b)
{
	int i;

	if (!(*head_b))
		ft_message_error(head_a, head_b, "ft_list_b_max : head doen't exist.");
		// ft_message_error(head_a, head_b);
	i = (*head_b)->index;
	
	while ((*head_b))
	{
		if (i < (*head_b)->index)
			i = (*head_b)->index;
		(*head_b) = (*head_b)->next;
	}
	printf("\nLIST B INDEX MAX = %d\n", i); // ! a supprimer

	return (i);
}

void ft_find_cost(t_list **head_a, t_list **head_b)
{
	// ft_pb_push_b(head_a, head_b, "pb");
	
	int	i;
	// int	cost;
	t_list *tmp;
	
	if (!(*head_a))
		ft_message_error(head_a, head_b, "ft_find_cost : head doen't exist.");
	
	i = 1;
	tmp = (*head_a);
	// tmp->cost = 1;
	
	while (tmp)
	{
		// if (tmp->index + 1 == ft_list_b_max(head_a, head_b))
		// 	i = cost;
		
		// if (tmp->index > (*head_b)->index)
		// {
		// 	if (i < cost)
		// 		cost = i++;
		// }
		// else
		// 	i++;

		tmp->cost = i;
		tmp = tmp->next;
		
		
		i++;
	}
	// printf("\ncheapest cost : %d\n", cost);
	

	// return (cost);
}


int	ft_cheapest_number(t_list **head_a, t_list **head_b)
{
	int	i;
	int	cost;
	t_list *tmp;

	if (!(*head_a))
		ft_message_error(head_a, head_b, "ft_cheapest_number : head doen't exist.");
		// ft_message_error(head_a, head_b);

	i = 1;
	cost = i;
	tmp = (*head_a);
	while (tmp)
	{
		if (tmp->index + 1 == ft_list_b_max(head_a, head_b)
			|| tmp->index - 1 < ft_list_b_min(head_a, head_b))
		
		ft_find_cost(head_a, head_b);
	}
	
	return(cost);

}

