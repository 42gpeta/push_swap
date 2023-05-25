/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:45:17 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/25 22:10:22 by gpeta            ###   ########.fr       */
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
}

int	ft_find_index_max_bit(int index_max)
{
	while (ft_find_max())
}