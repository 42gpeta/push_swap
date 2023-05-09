/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:15 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/09 19:21:53 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list list;
	t_list *node1;
	t_list *node2;

	int i;

	i = 2;
	
	/* Creer la structure */
	list.first = ft_lstnew(ft_atoi(av[1]));
	// list.first = ft_lstnew(list.first, ft_atoi(av[1]));

	// ft_create_node(52);
	// ft_lstadd_front(&list, node1);
	// ft_lstadd_back(list, node2)

	while (i < ac)
	{
		/* Lier les structures récupérées en av[@] */
		ft_lstadd_back(&list.first, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
	
	print_list(list.first);

	printf("ac = %d\n i = %d\n", ac, i);
	ft_free(list.first);
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