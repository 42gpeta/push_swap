#include "push_swap.h"

void	ft_pre_sort(t_list **head_a, t_list **head_b)
{
	int		size;
	int		i;

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
	}
}

void	ft_sort(t_list **head_a, t_list **head_b)
{
/* 	int		size;
	int		i;

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
	} */
		ft_pre_sort(head_a,  head_b);

		// ft_leave_three_biggest_in_a(head_a,head_b, size);
		// ft_sort_tree_node(head_a);
		ft_count_rb_and_rrb(head_b);
		ft_nearest_index_for_B_node(head_a, head_b);

		ft_pa_push_a(head_a, head_b, "pa");
		ft_ra_rotate_a(head_a, "ra");
		ft_pb_push_b(head_a, head_b, "pb");
		// ft_pb_push_b(head_a, head_b, "pb");
		ft_rra_reverse_rotate_a(head_a, "rra");
		ft_pa_push_a(head_a, head_b, "pa");
		
		ft_count_rb_and_rrb(head_b);
		ft_nearest_index_for_B_node(head_a, head_b);

		
		t_list *cheapest = ft_find_node_with_cheapest_ra_rb_shoot(head_a, head_b);

		printf("Le node avec le moins de coup est le %d[%d] coup = %d\n", cheapest->content, cheapest->index, (cheapest->ra + cheapest->rb));
	
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
	// while ((*head_a)->index != 1)
	// 	ft_ra_rotate_a(head_a, "ra");

}

void	ft_leave_three_biggest_in_a(t_list **head_a, t_list **head_b, int size)
{
	int		i;

	i = 0;

	while(*head_a && i <= ft_lstsize(*head_a))
	{
		if ((*head_a)->index <= (size - 3))
			ft_pb_push_b(head_a,head_b,"pb");
		else
			ft_ra_rotate_a(head_a,"ra");
		i++;
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
		printf("RB = %d\n", tmp->rb);
		tmp->rrb = ft_lstsize(*head_b) - tmp->rb;
		printf("RRB = %d\n", tmp->rrb);
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
			cheapest = tmp_b;
			ra_rb = tmp_b->ra + tmp_b->rb;
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
			cheapest = tmp_b;
			ra_rrb = tmp_b->ra + tmp_b->rrb;
		tmp_b = tmp_b->next; 
	}
	return (cheapest);
}