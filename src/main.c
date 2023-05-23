/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:15 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/23 19:35:43 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int ac, char **av)
// {
// 	t_list list;
// 	// t_list *node1;
// 	// t_list *node2;



// 	ft_init(&list);
// 	int i;

// 	i = 2;
	
//	/* Creer la structure */
// 	list.pile_a = ft_lstnew(ft_atoi(av[1]));

// 	while (i < ac)
// 	{
// 		/* Lier les structures récupérées en av[@] */
// 		ft_lstadd_back(&list.pile_a, ft_lstnew(ft_atoi(av[i])));
// 		i++;
// 	}
	
// 	print_list(&list.pile_a);

// 	printf("ac = %d\n i = %d\n", ac, i);

// 	ft_sa_swap_a(list.pile_a);
// 	print_list(&list.pile_a);
	
// 	ft_free(list.pile_a);
// 	return (0);
// }


int	main(int ac, char **av)
{
	t_list *list_a;
	t_list *list_b;

	list_a = NULL;
	list_b = NULL;
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

	
	print_list(list_a, 'a');
	print_list(list_b, 'b');
	
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
	

	// ft_list_a_five_node(&list_a, &list_b);
	// ft_list_a_four_node(&list_a, &list_b);
	// ft_list_a_tree_node(&list_a);
	ft_list_a_two_node(&list_a);
	
	
/* ***************** */
	
	print_list(list_a, 'a');
	print_list(list_b, 'b');


/* ***************** */
/*     FIN Prog     */
/* ***************** */

	ft_free(list_a, list_b);
	// ft_free(list_a);
	return (0);
}






// int	main(int ac, char **av)
// {
// 	t_list *list;
// 	t_list node1;
// 	t_list node2;
// 	t_list node3;
// 	t_list node4;
// 	int	i;

// 	ft_check_parameter(ac);
	
// 	// i = 2;
// 	// while (av[i])
// 	// {
// 	// 	ft_lstadd_front();
// 	// }

// 	list = &node1;
// 	node1.next = &node2;
// 	node2.next = &node3;
// 	node3.next = 0;

// 	// node1.content = ft_atoi(av[1]);
// 	// node2.content = ft_atoi(av[2]);
// 	// node3.content = ft_atoi(av[3]);
// 	// node4.content = ft_atoi(av[4]);
// 	// node4.content = (int *)144;
// 	// ft_lstadd_front(list, &node4);
	
// 	// ft_printf("%d\n", node4.content);
	
// 	list = ft_lstnew(1);

// 	ft_create_node(14);

// 	print_list(ft_create_node(ft_atoi(av[1])));
// 	print_list(list);

	
// 	write(1,"PUSH_SWAP\n", 10);
// 	print_swap("sa");

// 	return (0);
// }