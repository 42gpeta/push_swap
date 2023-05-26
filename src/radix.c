/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:45:17 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/26 21:20:11 by gpeta            ###   ########.fr       */
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
	int i = 1;
	int max_bit = index_max;
	
	while (max_bit != 0)
	{
		max_bit = max_bit >> 1;
		i++;
		// printf("index max = %d | i = %d\n", max_bit, i); // ! a supprimer
	}
	i++;
	printf("index max = %d | i = %d\n", max_bit, i);
	return (i);
}

void	ft_radix(t_list **head_a)
// void	ft_radix(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int		i;
	int		test;

	i = ft_find_index_max_bit(ft_find_max(head_a));


	tmp = (*head_a);
	// test = tmp->index & 1;
	// test = 24 | 0;
	test = 2 >> i;

	printf("LSB = %d\n", tmp->index >> i);
	printf("LSB test = %d\n", test);
	// while (i > 0)
	// {
	// 	printf("\n TOUR \n\n");
	// 	if (tmp->index >> i == 1)
	// 	{
	// 		ft_pb_push_b(head_a, head_b, "pb");
	// 		print_list(*head_a, 'a');
	// 		print_list(*head_b, 'b');
	// 	}
	// 	else
	// 	{
	// 		ft_ra_rotate_a(head_a, "ra");
	// 		print_list(*head_a, 'a');
	// 		print_list(*head_b, 'b');
	// 	}
	// 	i--;
	// 	printf("\n FIN TOUR \n\n");

	// }
}