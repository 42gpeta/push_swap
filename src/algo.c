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
	// ft_nearest_index(head_a,head_b,2,1);
	printf("greater : index[%d]", ft_nearest_index(head_a,2));

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
int	ft_nearest_index(t_list **head_a, int index_target)
{
	t_list *tmp;
	int		greater;

	tmp = (*head_a);
	
	// on cherche le plus petit ecart quand on se retourve avec un index > a l'index target
	greater = tmp->index;
	while (tmp)
	{
		if (tmp->index > index_target && tmp->index < greater)
			greater = tmp->index;
		tmp = tmp->next;
	}
	return (greater);
}