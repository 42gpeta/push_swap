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
	if (ft_lstsize(*head_a) > 2)
	{
		ft_leave_three_biggest_in_a(head_a,head_b, size);
		ft_sort_tree_node(head_a);
	}
	// ft_count_rb(head_b, (*head_b)->next->index);
	
	while ((*head_b))
	{

		ft_count_rb(head_b);
		ft_count_rrb(head_b);
		// printf("\ngreater : index[%d]", ft_nearest_index(head_a, head_b, 12)); // ! a supprimer

		// ft_rr_rotate_a_b(head_a,head_b,"rr");
		// ft_pa_push_a(head_a,head_b,"pa");
		// ft_rb_rotate_b(head_b,"rb");
		// ft_rrb_reverse_rotate_b(head_b,"rrb");
		// ft_rrb_reverse_rotate_b(head_b,"rrb");

		ft_count_ra(head_a, head_b);
		ft_count_rra(head_a, head_b);
		ft_index_of_best_combination(head_a, head_b);

		ft_execute_combination(head_a, head_b, ft_index_of_best_combination(head_a, head_b));
	}

	ft_raise_first_index(head_a, ft_up_first_index_ra(head_a), ft_up_first_index_rra(head_a));
	// while ((*head_a)->index != 1)
	// 	ft_ra_rotate_a(head_a, "ra");

	// t_list *target_a = ft_pull_ra_rra_from_nearest_index(head_a, head_b);

	// printf("node %d[%d] : ra|rra = %d|%d\n", target_a->content, target_a->index, target_a->ra, target_a->rra); // ! a supprimer 
	// printf("index du content %p\n", ft_pull_ra_rra_from_nearest_index(head_a, head_b));



}

void	ft_leave_three_biggest_in_a(t_list **head_a, t_list **head_b, int size)
{
	int		i;

	i = 0;

	while(*head_a && i <= size)
	{
		if ((*head_a)->index <= (size - 3))
			ft_pb_push_b(head_a,head_b,"pb");
		else
			ft_ra_rotate_a(head_a,"ra");
		i++;
	}
}

// void	ft_count_rb(t_list **head_b, int target_node)
void	ft_count_rb(t_list **head_b)
{
	int	i;
	t_list *tmp;

	i = -1;
	tmp = (*head_b);
	while (tmp)
	{
		tmp->rb = ++i;
		tmp = tmp->next;
	}

}

void	ft_count_rrb(t_list **head_b)
{
	t_list *tmp;

	tmp = (*head_b);
	while (tmp)
	{
		tmp->rrb = ft_lstsize(*head_b) - tmp->rb;
		tmp = tmp->next;
	}
}

// void	ft_nearest_index(t_list **head_a, t_list **head_b, int index_target, int i)

// Find the smaller in the list A greater than one relative to my target in list B
int	ft_nearest_index(t_list **head_a, t_list **head_b, int index_target)
{
	t_list *tmp;
	int		greater;

	tmp = (*head_a);
	
	// on cherche le plus petit ecart quand on se retourve avec un index > a l'index target
	// greater = tmp->index;
	greater = ft_lstsize(*head_a) + ft_lstsize(*head_b);
	while (tmp)
	{
		if (tmp->index > index_target && tmp->index < greater)
			greater = tmp->index;
		tmp = tmp->next;
	}
	return (greater);
}

int	ft_count_ra(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int	i;

	i = 0;
	tmp = (*head_a);
	while (tmp && tmp->index != ft_nearest_index(head_a, head_b, (*head_b)->index))
	{
		i++;
		// tmp->ra = i++;
		tmp = tmp->next;
	}
	tmp->ra = i;
	return (tmp->index);
}

void	ft_count_rra(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int	i;

	i = 0;
	tmp = (*head_a);
	while (tmp && tmp->index != ft_nearest_index(head_a, head_b, (*head_b)->index))
	{
		i++;
		// tmp->ra = i++;
		tmp = tmp->next;
	}
	tmp->rra = ft_lstsize(*head_a) - i;

}

int	ft_index_of_best_combination(t_list **head_a, t_list **head_b)
{
	int i;
	int min;
	int petit;
	int result[4];

	result[0] = ft_count_the_shoot_ra_rb(head_a, head_b);
	result[1] = ft_count_the_shoot_ra_rrb(head_a, head_b);
	result[2] = ft_count_the_shoot_rra_rb(head_a, head_b);
	result[3] = ft_count_the_shoot_rra_rrb(head_a, head_b);

	// for (i = 0; i < 4 ; i++) // ! a supprimer
	// 	printf("\nResultat index[%d]: %d\n", i, result[i]); // ! a supprimer

	i = 0;
	min = 0;
	petit = result[0];
	while (i < 4)
	{
		if (result[i] < petit)
		{	
			min = i;
			petit = result[i];
		}
		i++;
	}
	// printf("\nL'index le + petit est : %d\n", min); // ! a supprimer
	return (min);
}

int	ft_count_the_shoot_ra_rb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater); // ! a supprimer

	while (tmp->index != greater)
		tmp = tmp->next;
	// printf("\nra = %d | rb = %d \nsum = %d\n", tmp->ra, (*head_b)->rb, tmp->ra + (*head_b)->rb);
	return (tmp->ra + (*head_b)->rb);
}

int	ft_count_the_shoot_ra_rrb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater); // ! a supprimer

	while (tmp->index != greater)
		tmp = tmp->next;
	// printf("\nra = %d | rrb = %d \nsum = %d\n", tmp->ra, (*head_b)->rrb, tmp->ra + (*head_b)->rrb);
	return (tmp->ra + (*head_b)->rrb);
}

int	ft_count_the_shoot_rra_rb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater); // ! a supprimer

	while (tmp->index != greater)
		tmp = tmp->next;
	// printf("\nrra = %d | rb = %d \nsum = %d\n", tmp->rra, (*head_b)->rb, tmp->rra + (*head_b)->rb);
	return (tmp->rra + (*head_b)->rb);
}

int	ft_count_the_shoot_rra_rrb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater); // ! a supprimer

	while (tmp->index != greater)
		tmp = tmp->next;
	// printf("\nrra = %d | rrb = %d \nsum = %d\n", tmp->rra, (*head_b)->rrb, tmp->rra + (*head_b)->rrb);
	return (tmp->rra + (*head_b)->rrb);
}

void	ft_execute_combination(t_list **head_a, t_list **head_b, int number)
{
	if (number == 0)
		ft_execute_ra_rb(head_a, head_b, ft_pull_ra_rra_from_nearest_index(head_a, head_b));
	else if (number == 1)
		ft_execute_ra_rrb(head_a, head_b, ft_pull_ra_rra_from_nearest_index(head_a, head_b));
	else if (number == 2)
		ft_execute_rra_rb(head_a, head_b, ft_pull_ra_rra_from_nearest_index(head_a, head_b));
	else if (number == 3)
		ft_execute_rra_rrb(head_a, head_b, ft_pull_ra_rra_from_nearest_index(head_a, head_b));
}

void	*ft_pull_ra_rra_from_nearest_index(t_list **head_a, t_list **head_b)
{
	t_list *tmp;

	tmp = (*head_a);
	while(tmp && tmp->index != ft_nearest_index(head_a, head_b, (*head_b)->index))
		tmp = tmp->next;
	return (tmp);
}

void	ft_execute_ra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index)
{
	int	rb;
	
	rb = (*head_b)->rb;

	while (nearest_index->ra > 0 && rb > 0)
	{
		ft_rr_rotate_a_b(head_a, head_b, "rr");
		nearest_index->ra--;
		rb--;
	}
	while (nearest_index->ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		nearest_index->ra--;
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
	int	rrb;
	
	rrb = (*head_b)->rrb;

	// while (nearest_index->rra > 0 && rrb > 0)
	// {
	// 	ft_rrr_reverse_rotate_a_b(head_a, head_b, "rrr");
	// 	nearest_index->rra--;
	// 	rrb--;
	// }
	while (nearest_index->ra > 0)
	{
		ft_ra_rotate_a(head_a, "ra");
		nearest_index->ra--;
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
	int	rb;
	
	rb = (*head_b)->rb;

	// while (nearest_index->rra > 0 && rb > 0)
	// {
	// 	ft_rrr_reverse_rotate_a_b(head_a, head_b, "rrr");
	// 	nearest_index->rra--;
	// 	rb--;
	// }
	while (nearest_index->rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		nearest_index->rra--;
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
	int	rb;
	int	rrb;
	
	rb = (*head_b)->rb;
	rrb = (*head_b)->rrb;

	while (nearest_index->rra > 0 && rrb > 0)
	{
		ft_rrr_reverse_rotate_a_b(head_a, head_b, "rrr");
		nearest_index->rra--;
		rrb--;
	}
	while (nearest_index->rra > 0)
	{
		ft_rra_reverse_rotate_a(head_a, "rra");
		nearest_index->rra--;
	}
	while (rrb > 0)
	{
		ft_rrb_reverse_rotate_b(head_b, "rrb");
		rrb--;
	}
	ft_pa_push_a(head_a, head_b, "pa");
}

void	ft_raise_first_index(t_list **head_a, int ra, int rra)
{
	// printf("ra|rra : %d|%d\n", ra, rra); // ! a supprimer

	// ft_do_ra(head_a);


	if (ra < rra)
	{
		ft_do_ra(head_a);
		// printf("RA\n"); // ! a supprimer
	}
	else if (rra < ra)
	{
		ft_do_rra(head_a);
		// printf("RRA\n"); // ! a supprimer
	}


}

int		ft_up_first_index_ra(t_list **head_a)
{
	int nb_ra;
	t_list *tmp;

	nb_ra = 0;
	tmp = (*head_a);
	while (tmp->index != 1)
	{
		tmp = tmp->next;
		nb_ra++;
	}
		
	return (nb_ra);
}

int		ft_up_first_index_rra(t_list **head_a)
{
	int nb_rra;

	nb_rra = ft_lstsize(*head_a) - ft_up_first_index_ra(head_a);
	return (nb_rra);
}

void	ft_do_ra(t_list **head_a)
{
	int nb_ra;

	nb_ra = 0;
	while ((*head_a)->index != 1)
		ft_ra_rotate_a(head_a, "ra");
	// while (nb_ra < ft_up_first_index_ra(head_a))
	// {
	// 	ft_ra_rotate_a(head_a, "ra");
	// 	nb_ra++;
	// }
	// return (nb_ra);
}

void	ft_do_rra(t_list **head_a)
{
	int nb_rra;

	nb_rra = 0;
	while ((*head_a)->index != 1)
		ft_rra_reverse_rotate_a(head_a, "rra");
	// while (nb_rra < ft_up_first_index_rra(head_a))
	// {
	// 	ft_rra_reverse_rotate_a(head_a, "ra");
	// 	nb_rra++;
	// }
	// return (nb_rra);
}
