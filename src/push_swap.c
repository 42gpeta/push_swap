/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:28:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/03 00:49:11 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b)
{
	t_list	*list;
	int		is_add_back_ok;
	int		i;

	list = NULL;
	ft_check_args(av, head_a, head_b);
	i = 2;
	list = ft_lstnew(ft_atoi(av[1]));
	if (!list)
		ft_message_error(head_a, head_b);
	while (i < ac)
	{
		is_add_back_ok = ft_lstadd_back(&list, ft_lstnew(ft_atoi(av[i])));
		if (is_add_back_ok == -1)
			ft_message_error(&list, head_b);
		i++;
	}
	return (list);
}

void	ft_index(t_list **head)
{
	t_list	*tmp;
	t_list	*first;

	first = (*head);
	tmp = (*head);
	while (tmp)
	{
		tmp->index = 1;
		while (first)
		{
			if (tmp->content > first->content)
				tmp->index++;
			first = first->next;
		}
		tmp = tmp->next;
		first = (*head);
	}
}
