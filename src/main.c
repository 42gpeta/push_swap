/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:15 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 17:39:51 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;

	if (ac <= 2)
		return (0);
/* 	// ? version w/out fontion ft_linked_list()
	// ft_check_parameter(ac, av);
	// 
	// ft_init(list);
	
	// int i;
	// 
	// i = 2;
	// 
	// // Creer la structure
	// list = ft_lstnew(ft_atoi(av[1]));
	// if (!list)
	// 	ft_message_error();
	// 
	// while (i < ac)
	// {
	// 	// Lier les structures récupérées en av[@]
	// 	ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
	// 	i++;
	// }
	// ? version w/out fontion ft_linked_list() */
	list_a = ft_linked_list(ac, av, &list_a, &list_b);
	// list_b = ft_linked_list(ac, av);


	ft_index(&list_a);

	// ft_is_sorted(&list_a, &list_b);
	if (ft_is_sorted(&list_a) == 1)
	{
		ft_free(list_a, list_b);
		return (0);
	}
	
	// print_list(list_a, 'a');
	// print_list(list_b, 'b');
	
	// printf("\n\nsize = %d\n\n", ft_lstsize(list_a));
	// print_ac_i(i, ac); 	// ? version w/out fontion ft_linked_list()

/* ***************** */
/* Test instructions */
/* ***************** */

	// ft_sa_swap_a(&list_b, "sa");
	// ft_ra_rotate_a(&list_b, "ra");
	// ft_rra_reverse_rotate_a(&list_b, "rra");
	// ft_pa_push_a(&list_a, &list_b, "pa");
	
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pa_push_a(&list_a, &list_b, "pa");
	
	// ft_rrb_reverse_rotate_b(&list_b, "rrb");
	// ft_rb_rotate_b(&list_b, "rb");
	// ft_sb_swap_b(&list_b, "sb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	
	// ft_ss_swap_a_b(&list_a, &list_b, "ss");
	// ft_rr_rotate_a_b(&list_a, &list_b, "rr");
	
	// ft_rrr_reverse_rotate_a_b(&list_a, &list_b, "rrr");

	
	/* Exemple sujet */
	
	// ft_sa_swap_a(&list_a, "sa");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_ra_rotate_a(&list_a, "ra");
	// ft_ra_rotate_a(&list_a, "ra");
	// ft_rb_rotate_b(&list_b, "rb");
	// ft_rra_reverse_rotate_a(&list_a, "rra");
	// ft_rrb_reverse_rotate_b(&list_b, "rrb");
	// ft_sa_swap_a(&list_a, "sa");
	// ft_pa_push_a(&list_a, &list_b, "pa");
	// ft_pa_push_a(&list_a, &list_b, "pa");
	// ft_pa_push_a(&list_a, &list_b, "pa");
	
	

	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_ra_rotate_a(&list_a, "ra");

	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_ra_rotate_a(&list_a, "ra");

	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_pb_push_b(&list_a, &list_b, "pb");
	// ft_rb_rotate_b(&list_b, "rb");
	

	// ft_sort_five_node(&list_a, &list_b); // ! non OK
	
	// printf("%d nodes\n", ac - 1); // ! a supprimer
	if (ac == 3)
		ft_sort_two_node(&list_a);
	else if (ac == 4)
		ft_sort_tree_node(&list_a);
	else if (ac == 5)
		ft_sort_four_node(&list_a, &list_b);
	else if (ac == 6)
		ft_sort_five_node(&list_a, &list_b);
	else
		ft_sort(&list_a, &list_b);
	
	
/* ***************** */
	
	// print_list(list_a, 'a');
	// print_list(list_b, 'b');


/* ***************** */
/*     FIN Prog     */
/* ***************** */

	ft_free(list_a, list_b);
	// ft_free(list_a);
	return (0);
}
