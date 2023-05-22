/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:28:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/22 17:47:18 by gpeta            ###   ########.fr       */
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
		tmp->index = 0;
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

// void	ft_push_first_filter(t_list **head_a)
void	ft_push_first_filter(t_list **head_a, t_list **head_b)
{
	int		size;
	int		i = 0;
	// int		test = 1;
	// t_list	*tmp;
	size = 0;
	size = ft_lstsize(*head_a);
	// tmp = (*head_a);
	
	/* test du pourcentage de l'index */
	// if (test < (size  / 3 * 1))
	// 	printf("size = %2.f | test = %2.f\n%.2f < à %.2f (1/3) de %.f\n", size, test, (test / size), 0.33, size);
	// else if (test < (size / 3 * 2))
	// 	printf("size = %2.f | test = %2.f\n%.2f < à %.2f (2/3) de %.f\n", size, test, (test / size), 0.67, size);
	// else
	// 	printf("size = %2.f | test = %2.f\n%.2f > à %.2f (2/3) de %.f\n", size, test, (test / size), 0.67, size);
	
	// while (tmp != NULL)
	// {
	// 	if (tmp->index < (size / 3 * 2) && ft_lstsize(*head_a) > 1)
	// 	{
	// 		ft_pb_push_b(head_a, head_b, "pb");
	// 		if (tmp->index < (size / 3 * 1))
	// 		{
	// 			ft_rb_rotate_b(head_b, "rb");
	// 		}
	// 	}
	// 	else
	// 		ft_ra_rotate_a(head_a, "ra");
	// 	tmp = tmp->next;
	// }


	// printf("tete b : %p\n", head_b);
	// printf("tete b : %d\n", (*head_a)->index);
	// printf("%%size : %f\n", (size * 0.67));
	// printf("%%size : %d\n", (size / 3 * 2));
	// printf("%%size : %d\n", (size / 3 * 1));

	// while (ft_lstsize(*head_a) > 1)
	while (*head_a && i < size)
	{
		if ((*head_a)->index < (size / 3 * 2) )
		{
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->index <= (size / 3))
				ft_rb_rotate_b(head_b, "rb");
		}
		else
			ft_ra_rotate_a(head_a, "ra");
		i++;
	}
}