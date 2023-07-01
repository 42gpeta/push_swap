/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:38:47 by glodi             #+#    #+#             */
/*   Updated: 2023/07/01 18:26:02 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_sort_five_node(t_list **head_a, t_list **head_b) // ! non terminée ; ? v1
// {
// 	// if (ft_lstsize(*head_a) == 3)
// 	// 	ft_sort_tree_node(head_a);

// 	// else if (ft_lstsize(*head_a) > 4)
// 	// {
		
// 	int i;

// 	i = 0;
// 	while ((*head_a) && i < 5)
// 	{
// 		if ((*head_a)->index > 3)
// 			ft_pb_push_b(head_a, head_b, "pb");
// 		(*head_a) = (*head_a)->next;
// 		i++;
// 	}
// 	if ((*head_b)->index < (*head_b)->next->index)
// 		ft_rb_rotate_b(head_b, "rb");
// 	print_list(head_a, 'a');
// 	print_list(head_b, 'b');
// 	ft_sort_tree_node(head_a);
// 	ft_pa_push_a(head_a, head_b, "pa");
// 	ft_pa_push_a(head_a, head_b, "pa");
// 		// while ((*head_a)->index != (*head_b)->index + 1)
// 	// }
// 	printf("5!\n");
// }

void	ft_sort_five_node(t_list **head_a, t_list **head_b) // ! non terminée ; ? v2
{
	// if (ft_lstsize(*head_a) == 3)
	// 	ft_sort_tree_node(head_a);

	// else if (ft_lstsize(*head_a) > 4)
	// {
		
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
		// stop = ft_lstsize(*head_a);
	}	
	
		
	// print_list(head_a, 'a');
	// print_list(head_b, 'b');
	ft_sort_tree_node(head_a);
	ft_pa_push_a(head_a, head_b, "pa");
	ft_pa_push_a(head_a, head_b, "pa");
		// while ((*head_a)->index != (*head_b)->index + 1)
	// }
	// printf("5!\n"); // ! a supprimer
}

// void	ft_sort_four_node(t_list **head_a)
// void	ft_sort_four_node(t_list **head_a, t_list **head_b) // ? v1
// {
// 	int		size;
// 	int		i = 0;
// 	// int		test = 1;
// 	// t_list	*tmp;
// 
// 	if (!(*head_a))
// 		return ;
// 
// 	size = 0;
// 	size = ft_lstsize(*head_a);
// 	// tmp = (*head_a);
// 
// 	/* test du pourcentage de l'index */
// 	// if (test < (size  / 3 * 1))
// 	// 	printf("size = %2.f | test = %2.f\n%.2f < à %.2f (1/3) de %.f\n", size, test, (test / size), 0.33, size);
// 	// else if (test < (size / 3 * 2))
// 	// 	printf("size = %2.f | test = %2.f\n%.2f < à %.2f (2/3) de %.f\n", size, test, (test / size), 0.67, size);
// 	// else
// 	// 	printf("size = %2.f | test = %2.f\n%.2f > à %.2f (2/3) de %.f\n", size, test, (test / size), 0.67, size);
// 
// 	// while (tmp != NULL)
// 	// {
// 	// 	if (tmp->index < (size / 3 * 2) && ft_lstsize(*head_a) > 1)
// 	// 	{
// 	// 		ft_pb_push_b(head_a, head_b, "pb");
// 	// 		if (tmp->index < (size / 3 * 1))
// 	// 		{
// 	// 			ft_rb_rotate_b(head_b, "rb");
// 	// 		}
// 	// 	}
// 	// 	else
// 	// 		ft_ra_rotate_a(head_a, "ra");
// 	// 	tmp = tmp->next;
// 	// }
// 
// 
// 	// printf("tete b : %p\n", head_b);
// 	// printf("tete b : %d\n", (*head_a)->index);
// 	// printf("%%size : %d\n", (size / 3 * 2) / 2);
// 	// printf("%%size : %d\n", (size / 3 * 2));
// 	// printf("%%size : %d\n", (size / 3 * 1));
// 
// 	while (*head_a && i < size)
// 	{
// 		if ((*head_a)->index <= (size / 3 * 2))
// 		{
// 			ft_pb_push_b(head_a, head_b, "pb");
// 			if ((*head_b)->index < ((size / 3 * 2) / 2))
// 				ft_rb_rotate_b(head_b, "rb");
// 		}
// 		else
// 			ft_ra_rotate_a(head_a, "ra");
// 		i++;
// 	}
// 
// 	// while ((*head_a))
// 	// {
// 		// if ((*head_a)->index < size - 3)
// 		while ((*head_a)->index < size - 3)
// 		{
// 			ft_pb_push_b(head_a, head_b, "pb");
// 			if ((*head_b)->index < ((size / 3 * 2) / 2))
// 				ft_rb_rotate_b(head_b, "rb");		
// 		}
// 	// }
// 	print_list_size(*head_a);
// }

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
				// ft_sa_swap_a(head_a, "sa");
			i++;
		}
		ft_pa_push_a(head_a, head_b, "pa");
		while ((*head_a)->index != 1)
			ft_ra_rotate_a(head_a, "ra");
			// ft_sa_swap_a(head_a, "sa");
	}
	// else if (ft_lstsize(*head_a) > 4)
}


void	ft_sort_tree_node(t_list **head_a)
{
	// 1 2 3
	if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
		return ;
	//**********************************************
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
	//**********************************************
	// 2 1 3 et 3 1 2
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index)
			ft_sa_swap_a(head_a, "sa");
		else if ((*head_a)->index > (*head_a)->next->next->index)
			ft_ra_rotate_a(head_a, "ra");
	}	
	//**********************************************
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
	// ft_message_error(head_a, head_b, "ft_is_sorted : OK"); // TODO envoyer : "OK"
	return (1);
	
}