/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:45:17 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/26 20:28:25 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list **head_a)
{
	int		index_max;
	t_list	*tmp;
	
	index_max = ft_lstsize(*head_a);
	tmp = (*head_a);
	while (tmp->index != index_max)
	{
		tmp = tmp->next;
	}
	// printf("INDEX MAX = %d\n", tmp->index); // ! a supprimer
	return (tmp->index);
}

int	ft_find_index_max_bit(int index_max)
{
	int i = 0;
	int max_bit = index_max;
	
	printf("index max = %d | i = %d\n", max_bit, i);
	while (max_bit != 0)
	{
		max_bit = max_bit >> 1;
		i++;
		// printf("index max = %d | i = %d\n", max_bit, i); // ! a supprimer
		
	}
	return (i);
}

void	ft_radix(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int		i;

	i = 0;

	tmp = (*head_a);

	printf("LSB = %d\n", tmp->index & 1);
	// while (i < ft_find_index_max_bit(ft_find_max(head_a)))
	// {
	// 	if (tmp->index & 1)
	// }
}