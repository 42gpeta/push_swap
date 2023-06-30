#include "push_swap.h"

int	ft_pre_sort(t_list **head_a, t_list **head_b, int size)
{
	// int		size;
	int		i;


	// size = ft_lstsize(*head_a);
	i = 0;
	while (*head_a && i < size)
	{
		if ((*head_a)->index <= (size / 3 * 2))
		{
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->index <= ((size / 3 * 2) / 2)
				&& (*head_a)->index > (size / 3 * 2)) // si tete_b < 2/3 ET tete_a > 2/3
				ft_rr_rotate_a_b(head_a, head_b, "rr");
			else if ((*head_b)->index <= ((size / 3 * 2) / 2))
				ft_rb_rotate_b(head_b, "rb");
		}
		else
			ft_ra_rotate_a(head_a, "ra");
		i++;
	}
	size = ft_lstsize(*head_a);
	return (size);
}

void	ft_sort(t_list **head_a, t_list **head_b)
{
 	int		size = ft_lstsize(*head_a);
/*	int		i;

	size = ft_lstsize(*head_a);
	i = 0;
	while (*head_a && i < size)
	{
		if ((*head_a)->index <= (size / 3 * 2))
		{
			ft_pb_push_b(head_a, head_b, "pb");
			if ((*head_b)->index <= ((size / 3 * 2) / 2)
				&& (*head_a)->index > (size / 3 * 2)) // si tete_b < 2/3 ET tete_a > 2/3
				ft_rr_rotate_a_b(head_a, head_b, "rr");
			else if ((*head_b)->index <= ((size / 3 * 2) / 2))
				ft_rb_rotate_b(head_b, "rb");
		}
		else
			ft_ra_rotate_a(head_a, "ra");
		i++;
	} */ // ? correspond à ft_pre_sort()
		
	// ft_pre_sort(head_a, head_b, size);
	if (size != 6)
	{

		ft_leave_three_biggest_in_a(head_a,head_b, size, ft_pre_sort(head_a, head_b, size));
		ft_sort_tree_node(head_a);
	}
	// if (ft_lstsize(head_a) > 2)
	else
	{
		if ((*head_a)->index > (*head_a)->next->index)
			ft_ra_rotate_a(head_a, "ra");
	}

	while ((*head_b))
	{
			// ft_count_rb_and_rrb(head_b);
			// ft_nearest_index_for_B_node(head_a, head_b);

	// **********************************************************
			// ft_pa_push_a(head_a, head_b, "pa");
			// ft_ra_rotate_a(head_a, "ra");
			// ft_pb_push_b(head_a, head_b, "pb");
			// // ft_pb_push_b(head_a, head_b, "pb");
			// ft_rra_reverse_rotate_a(head_a, "rra");
			// ft_pa_push_a(head_a, head_b, "pa");
	// **********************************************************

			ft_nearest_index_for_B_node(head_a, head_b);
			ft_count_rb_and_rrb(head_b);

			// printf("cheapest shoot index = %d\n", ft_choose_best_combination(head_a, head_b));

			/* t_list *test = ft_choose_best_combination(head_a, head_b);
			printf("CHEAPEST 1 Node visé %d[%d] \n", test->content, test->index); */

		/* t_list *cheapest1 = ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b);
			t_list *cheapest2 = ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b);
			t_list *cheapest3 = ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b);
			t_list *cheapest4 = ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b);

			printf("Méthode 1/ node à bouger %d[%d] coup = %d\n", cheapest1->content, cheapest1->index, (cheapest1->ra + cheapest1->rb));
			printf("Méthode 2/ node à bouger %d[%d] coup = %d\n", cheapest2->content, cheapest2->index, (cheapest2->ra + cheapest2->rb));
			printf("Méthode 3/ node à bouger %d[%d] coup = %d\n", cheapest3->content, cheapest3->index, (cheapest3->ra + cheapest3->rb));
			printf("Méthode 4/ node à bouger %d[%d] coup = %d\n", cheapest4->content, cheapest4->index, (cheapest4->ra + cheapest4->rb)); */

			ft_execute_best_combination(head_a, head_b, ft_choose_best_combination(head_a, head_b));
	}

	// while ((*head_b))
	// {

	// 	ft_count_rb(head_b);
	// 	ft_count_rrb(head_b);
	// 	// printf("\ngreater : index[%d]", ft_nearest_index(head_a, head_b, 12)); // ! a supprimer

	// 	// ft_rr_rotate_a_b(head_a,head_b,"rr");
	// 	// ft_pa_push_a(head_a,head_b,"pa");
	// 	// ft_rb_rotate_b(head_b,"rb");
	// 	// ft_rrb_reverse_rotate_b(head_b,"rrb");
	// 	// ft_rrb_reverse_rotate_b(head_b,"rrb");

	// 	ft_count_ra(head_a, head_b);
	// 	ft_count_rra(head_a, head_b);
	// 	ft_index_of_best_combination(head_a, head_b);

	// 	ft_execute_combination(head_a, head_b, ft_index_of_best_combination(head_a, head_b));
	// }
	
	
/* 	while ((*head_a)->index != 1)
		ft_ra_rotate_a(head_a, "ra"); */ // ? ft_put_index_one_on_top()
	ft_put_index_one_on_top(head_a);

}

void	ft_leave_three_biggest_in_a(t_list **head_a, t_list **head_b, int max_index, int size)
{
	int		i;
	// int		stop;

	// i = size;
	// stop = ft_lstsize(*head_a);
	// while(*head_a && i < ft_lstsize(*head_a))
	while(size > 0)
	{

		if ((*head_a)->index > (max_index - 3))
		{
			ft_ra_rotate_a(head_a,"ra");
		}
		else
			ft_pb_push_b(head_a,head_b,"pb");
		size--;
		// stop = ft_lstsize(*head_a);
	}
}

// Trouve l'index supérieur le + proche de chaque node de B 
void	ft_nearest_index_for_B_node(t_list **head_a, t_list **head_b)
{
	t_list *tmp_a;
	t_list *tmp_b;
	int		nearest_index;
	int		i;

	tmp_b = *head_b;
	while (tmp_b)
	{
		tmp_a = *head_a;
		i = 0;
		nearest_index = ft_lstsize(*head_a) + ft_lstsize(*head_b);
		// printf("\e[103;5mnodeB : %d\e[0m\n", tmp_b->index); // ! a supprimer
		// printf("nearest : %d\n", nearest_index); // ! a supprimer
		while (tmp_a)
		{
			// printf("tmp_a index : %d\n --> %d > %d = %d\n  --> %d < %d = %d\n",tmp_a->index, tmp_a->index, tmp_b->index, (tmp_a->index > tmp_b->index), tmp_a->index, nearest_index, (tmp_a->index < nearest_index)); // ! a supprimer
			if (tmp_a->index > tmp_b->index && tmp_a->index < nearest_index)
			{
				nearest_index = tmp_a->index;
				tmp_b->ra = i;
				tmp_b->rra = ft_lstsize(*head_a) - tmp_b->ra;
				// printf("  \e[31mnew_rearest = %d\n -> tmp_b->ra = %i\e[0m\n", nearest_index, i); // ! a supprimer
			}
			tmp_a = tmp_a->next;
			i++;
		}
		tmp_b = tmp_b->next;
	}
}

void	ft_count_rb_and_rrb(t_list **head_b)
{
	int	i;
	t_list *tmp;

	i = 0;
	tmp = *head_b;
	while (tmp)
	{
		tmp->rb = i;
		tmp->rrb = ft_lstsize(*head_b) - tmp->rb;
		tmp = tmp->next;
		i++;
	}
	// tmp->rrb = ft_lstsize(*head_b) - tmp->rb;

}

t_list	*ft_find_node_with_cheapest_ra_rb_shoot(t_list **head_a, t_list **head_b)
{
	t_list *tmp_b;
	t_list *cheapest;
	int ra_rb;

	tmp_b = *head_b;
	ra_rb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->ra + tmp_b->rb) < ra_rb)
		{
			cheapest = tmp_b;
			ra_rb = tmp_b->ra + tmp_b->rb;
		}	
		tmp_b = tmp_b->next; 
	}
	return (cheapest);
}

t_list	*ft_find_node_with_cheapest_ra_rrb_shoot(t_list **head_a, t_list **head_b)
{
	t_list *tmp_b;
	t_list *cheapest;
	int ra_rrb;

	tmp_b = *head_b;
	ra_rrb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->ra + tmp_b->rrb) < ra_rrb)
		{
			cheapest = tmp_b;
			ra_rrb = tmp_b->ra + tmp_b->rrb;
		}	
		tmp_b = tmp_b->next; 
	}
	return (cheapest);
}

t_list	*ft_find_node_with_cheapest_rra_rb_shoot(t_list **head_a, t_list **head_b)
{
	t_list *tmp_b;
	t_list *cheapest;
	int rra_rb;

	tmp_b = *head_b;
	rra_rb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->rra + tmp_b->rb) < rra_rb)
		{
			cheapest = tmp_b;
			rra_rb = tmp_b->rra + tmp_b->rb;
		}	
		tmp_b = tmp_b->next; 
	}
	return (cheapest);
}

t_list	*ft_find_node_with_cheapest_rra_rrb_shoot(t_list **head_a, t_list **head_b)
{
	t_list *tmp_b;
	t_list *cheapest;
	int rra_rrb;

	tmp_b = *head_b;
	rra_rrb = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp_b)
	{
		if ((tmp_b->rra + tmp_b->rrb) < rra_rrb)
		{
			cheapest = tmp_b;
			rra_rrb = tmp_b->rra + tmp_b->rrb;
		}
		tmp_b = tmp_b->next; 
	}
	return (cheapest);
}

int	ft_choose_best_combination(t_list **head_a, t_list **head_b)
{
	int cheapest[4];
	int i;
	int index_w_cheapest_shoot;
	int smallest_sum;

	cheapest[0] = ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->ra + ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->rb;
	// printf("TOTAL CHEAPEST 1 = %d\n", cheapest[0]); // ! a supprimer
	cheapest[1] = ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b)->ra + ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b)->rrb;
	// printf("TOTAL CHEAPEST 2 = %d\n", cheapest[1]); // ! a supprimer
	cheapest[2] = ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b)->rra + ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b)->rb;
	// printf("TOTAL CHEAPEST 3 = %d\n", cheapest[2]); // ! a supprimer
	cheapest[3] = ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b)->rra + ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b)->rrb;
	// printf("TOTAL CHEAPEST 4 = %d\n", cheapest[3]); // ! a supprimer
	
	i = 0;
	// index_w_cheapest_shoot = 0; // ! a supprimer
	smallest_sum = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (i < 4)
	{
		// printf("index: %d | sum: %d\n", index_w_cheapest_shoot, smallest_sum); // ! a supprimer
		if (cheapest[i] < smallest_sum)
		{	
			index_w_cheapest_shoot = i;
			smallest_sum = cheapest[i];
		}
		i++;

	}
	// printf("\nLe node avec le sum le + petit est: %d[%d]\n", ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->content, ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b)->index); // ! a supprimer
	return (index_w_cheapest_shoot);
}

void	ft_execute_best_combination(t_list **head_a, t_list **head_b, int index)
{
	if (index == 0)
		ft_execute_ra_rb(head_a, head_b, ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b));
	else if (index == 1)
		ft_execute_ra_rrb(head_a, head_b, ft_find_node_with_cheapest_ra_rrb_shoot(head_a, head_b));
	else if (index == 2)
		ft_execute_rra_rb(head_a, head_b, ft_find_node_with_cheapest_rra_rb_shoot(head_a, head_b));
	else if (index == 3)
		ft_execute_rra_rrb(head_a, head_b, ft_find_node_with_cheapest_rra_rrb_shoot(head_a, head_b));


	// return (index_w_cheapest_shoot);
}

void	ft_execute_ra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int ra;
	int	rb;

	ra = nearest_index->ra;
	rb = nearest_index->rb;

	while (ra > 0 && rb > 0)
	{
		ft_rr_rotate_a_b(head_a, head_b, "rr");
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		ra--;
	}
	while (rb > 0)
	{
		ft_rb_rotate_b(head_b, "rb");
		rb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_ra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int ra;
	int	rrb;

	ra = nearest_index->ra;
	rrb = nearest_index->rrb;

	while (ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		ra--;
	}
	while (rrb > 0)
	{
		ft_rrb_reverse_rotate_b(head_b, "rrb");
		rrb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_rra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int rra;
	int	rb;

	rra = nearest_index->rra;
	rb = nearest_index->rb;

	while (rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		rra--;
	}
	while (rb > 0)
	{
		ft_rb_rotate_b(head_b, "rb");
		rb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_execute_rra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int rra;
	int	rrb;

	rra = nearest_index->rra;
	rrb = nearest_index->rrb;

	while (rra > 0 && rrb > 0)
	{
		ft_rrr_reverse_rotate_a_b(head_a, head_b, "rrr");
		rra--;
		rrb--;
	}
	while (rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		rra--;
	}
	while (rrb > 0)
	{
		ft_rrb_reverse_rotate_b(head_b, "rrb");
		rrb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_put_index_one_on_top(t_list **head_a)
{
	t_list *tmp_a;
	int		ra;
	int		rra;

	tmp_a = *head_a;

	while (tmp_a->index != 1)
	{
		tmp_a = tmp_a->next;
		ra++;
	}

	rra = ft_lstsize(*head_a) - ra;

	// printf("ra | rra :\n%d | %d\n", ra, rra); // ! a supprimer
	if (ra < rra)
	{
		while ((*head_a)->index != 1)
			ft_ra_rotate_a(head_a, "ra");
	}
	else
	{
		while ((*head_a)->index != 1)
			ft_rra_reverse_rotate_a(head_a, "rra");
	}

}
