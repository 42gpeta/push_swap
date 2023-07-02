/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:28:42 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/02 23:26:27 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_swap(char *instruction)
{
	if (ft_strncmp(instruction, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		write(1, "sb\n", 3);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		write(1, "ss\n", 3);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		write(1, "pb\n", 3);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		write(1, "rrb\n", 4);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		write(1, "rrr\n", 4);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		write(1, "rb\n", 3);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		write(1, "rr\n", 3);
}

void	print_list(t_list *node, char letter) // ! a supprimer
{
	t_list	*tmp;

	tmp = node;

	if (letter == 'a')
	{
		printf("\n*** PRINT LIST %c (%d nodes) ***\n", letter, ft_lstsize(node));
		while (tmp != NULL)
		{
			ft_printf("%d [%d] -> ", tmp->content, tmp->index);
			// ft_printf("%d [%d] ra|rra = %d|%d --->  \n", tmp->content, tmp->index, tmp->ra, tmp->rra);
			tmp = tmp->next;
		}
		printf("NULL \n");
		printf("***********************\n");
	}	
	else
	{
		printf("\n*** PRINT LIST %c (%d nodes) ***\n", letter, ft_lstsize(node));
		while (tmp != NULL)
		{
			// ft_printf("%d [%d] -> ", tmp->content, tmp->index);
			ft_printf("%d [%d] rb|rrb = %d|%d ; ra|rra = %d|%d --->  \n", tmp->content, tmp->index, tmp->rb, tmp->rrb, tmp->ra, tmp->rra);
			tmp = tmp->next;
		}
		printf("NULL \n");
		printf("***********************\n");
	}
}

void	print_list_size(t_list *head) // ! a supprimer
{
	printf("\nsize list : %d\n\n", ft_lstsize(head));
}

void	print_ac_i(int i, int ac) // ! a supprimer
{
	printf("ac = %d\n i = %d\n", ac, i);
}
