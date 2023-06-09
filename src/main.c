/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:15 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/03 00:39:00 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	ft_is_enough_parameter(ac);
	list_a = ft_linked_list(ac, av, &list_a, &list_b);
	ft_index(&list_a);
	if (ft_is_sorted(&list_a) == 1)
	{
		ft_free(list_a, list_b);
		return (0);
	}
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
	ft_free(list_a, list_b);
	return (0);
}
