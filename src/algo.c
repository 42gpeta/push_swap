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
	ft_count_rb(head_b);
	ft_count_rrb(head_b);
	printf("\ngreater : index[%d]", ft_nearest_index(head_a, head_b, 12)); // ! a supprimer

	// ft_rr_rotate_a_b(head_a,head_b,"rr");
	// ft_pa_push_a(head_a,head_b,"pa");
	// ft_rb_rotate_b(head_b,"rb");
	// ft_rrb_reverse_rotate_b(head_b,"rrb");
	// ft_rrb_reverse_rotate_b(head_b,"rrb");

	// ft_count_ra(head_a, head_b);
	ft_count_rra(head_a, head_b);
	ft_best_combination(head_a, head_b);



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

void	ft_best_combination(t_list **head_a, t_list **head_b)
{
	// int ra_rb;
	// int ra_rrb;
	// int rra_rb;
	// int rra_rrb;
	int i;
	int min;
	int petit;
	int result[4];

	result[0] = ft_combine_ra_rb(head_a, head_b);
	result[1] = ft_combine_ra_rrb(head_a, head_b);
	result[2] = ft_combine_rra_rb(head_a, head_b);
	result[3] = ft_combine_rra_rrb(head_a, head_b);

	for (i = 0; i < 4 ; i++) // ! a supprimer
		printf("\nResultat index[%d]: %d\n", i, result[i]); // ! a supprimer

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
	printf("\nL'index le + petit est : %d\n", min);
}

int	ft_combine_ra_rb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater);

	while (tmp->index != greater)
		tmp = tmp->next;
	printf("\nra = %d | rb = %d \nsum = %d\n", tmp->ra, (*head_b)->rb, tmp->ra + (*head_b)->rb);
	return (tmp->ra + (*head_b)->rb);
}

int	ft_combine_ra_rrb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater);

	while (tmp->index != greater)
		tmp = tmp->next;
	printf("\nra = %d | rrb = %d \nsum = %d\n", tmp->ra, (*head_b)->rrb, tmp->ra + (*head_b)->rrb);
	return (tmp->ra + (*head_b)->rrb);
}

int	ft_combine_rra_rb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater);

	while (tmp->index != greater)
		tmp = tmp->next;
	printf("\nrra = %d | rb = %d \nsum = %d\n", tmp->rra, (*head_b)->rb, tmp->rra + (*head_b)->rb);
	return (tmp->rra + (*head_b)->rb);
}

int	ft_combine_rra_rrb(t_list **head_a, t_list **head_b)
{
	t_list *tmp;
	int greater;
	
	tmp = (*head_a);
	greater = ft_count_ra(head_a, head_b);
	// printf("\nindex de a visé %d\n", greater);

	while (tmp->index != greater)
		tmp = tmp->next;
	printf("\nrra = %d | rrb = %d \nsum = %d\n", tmp->rra, (*head_b)->rrb, tmp->rra + (*head_b)->rrb);
	return (tmp->rra + (*head_b)->rrb);
}