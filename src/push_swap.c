/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:28:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/23 18:28:07 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_init(t_list **structure, int ac)
// {
// 	(*structure) = NULL;
	
// 	(*structure)->index = ac;
// 	structure->pile_a = 0;
// 	structure->pile_b = 0;
// }

t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b)
{
	t_list *list;

	list = NULL;
	// ft_check_parameter(ac, av, head_a, head_b);
	ft_check_parameter(ac, head_a, head_b);
	ft_check_args(av, head_a, head_b);
	
	int i;

	i = 2;
	
	/* Creer la structure */
	list = ft_lstnew(ft_atoi(av[1]));
	if (!list)
		ft_message_error(head_a, head_b, "ft_linked_list : 'List' doesn't exist"); // ! a supprimer
		// ft_message_error(head_a, head_b);
	// ft_init(&list, ac); // ? utile ?

	while (i < ac)
	{
		/* Lier les structures récupérées en av[@] */
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		i++;
	}

	// print_ac_i(i, ac); // ! a supprimer

	return (list);
}

void	ft_index(t_list **head)
{
	t_list	*tmp;
	t_list	*first;
	
	first = (*head);
	tmp = (*head);
	
	while (tmp)
	{
		tmp->index = 1;
		while (first)
		{
			if (tmp->content > first->content)
				tmp->index++;
			first = first->next;
		}
		tmp = tmp->next;
		first = (*head);
	}
}

void	ft_list_a_five_node(t_list **head_a, t_list **head_b) // ? v1
{
	if (ft_lstsize(*head_a) == 3)
		ft_list_a_tree_node(head_a);

	else if (ft_lstsize(*head_a) > 4)
	{
		while ((*head_a) && ft_lstsize(*head_a) > 3)
		{
			ft_pb_push_b(head_a, head_b, "pb");
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->index < (*head_b)->next->index)
				ft_rb_rotate_b(head_b, "rb");
		}
		ft_list_a_tree_node(head_a);
		while ((*head_a)->index != (*head_b)->index + 1)
	}
}


// void	ft_list_a_four_node(t_list **head_a)
// void	ft_list_a_four_node(t_list **head_a, t_list **head_b) // ? v1
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

void	ft_list_a_four_node(t_list **head_a, t_list **head_b) // ? v2
{
	int i = 0;
	
	if (ft_lstsize(*head_a) == 3)
		ft_list_a_tree_node(head_a);
	
	else if (ft_lstsize(*head_a) > 3)
	{
		ft_pb_push_b(head_a, head_b, "pb");
		ft_list_a_tree_node(head_a);
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


// void	ft_push_list_b_to_list_a(t_list **head_a, t_list **head_b)
// {
	
// }

void	ft_list_a_tree_node(t_list **head_a)
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
