/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:15 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/12 20:02:05 by gpeta            ###   ########.fr       */
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
	
// 	/* Creer la structure */
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
	t_list *list;

	list = NULL;
	ft_check_parameter(ac, av);

	ft_init(list);
	int i;

	i = 2;
	
	/* Creer la structure */
	list = ft_lstnew(ft_atoi(av[1]));
	if (!list)
		ft_message_error();

	while (i < ac)
	{
		/* Lier les structures récupérées en av[@] */
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	
	print_list(list);

	printf("ac = %d\n i = %d\n", ac, i);

	// ft_sa_swap_a(&list);
	ft_ra_rotate_a(&list);
	
	print_list(list);
	
	ft_free(list);
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