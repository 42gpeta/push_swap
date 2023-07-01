/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:28:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 18:25:33 by glodi            ###   ########.fr       */
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

// t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b) // ? v1
// {
// 	t_list *list;
// 	int is_add_back_ok;

// 	list = NULL;
// 	// ft_check_parameter(ac, av, head_a, head_b);
// 	ft_check_parameter(ac, head_a, head_b);
// 	ft_check_args(av, head_a, head_b);
	
// 	int i;

// 	i = 2;
	
// 	/* Creer la structure */
// 	list = ft_lstnew(ft_atoi(av[1]));
// 	if (!list)
// 		ft_message_error(head_a, head_b, "ft_linked_list : 'List' doesn't exist"); // ! a supprimer
// 		// ft_message_error(head_a, head_b);
// 	// ft_init(&list, ac); // ? utile ?

// 	while (i < ac)
// 	{
// 		/* Lier les structures récupérées en av[@] */
// 		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
// 		i++;
// 	}

// 	// print_ac_i(i, ac); // ! a supprimer

// 	return (list);
// }

t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b) // ? v2
{
	t_list *list;
	int is_add_back_ok;

	list = NULL;
	// ft_check_parameter(ac, av, head_a, head_b);
	
	// ft_check_parameter(ac, head_a, head_b);
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
		is_add_back_ok = ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		if (is_add_back_ok == -1)
		{
			// free(list);
			ft_message_error(&list, head_b, "lstadd_back fail");
			// ft_message_error(head_a, head_b);
		}
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


