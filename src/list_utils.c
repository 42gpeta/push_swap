/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:38:18 by glodi             #+#    #+#             */
/*   Updated: 2023/07/03 00:05:48 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_utils.h"

/* Création d'un node */
t_list	*ft_create_node(int data)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list) * 1);
	if (!cell)
		return (NULL);
	cell->content = data;
	cell->next = NULL;
	return (cell);
}

void	ft_free(t_list *head_a, t_list *head_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (head_a == NULL)
		return ;
	tmp_a = head_a->next;
	free(head_a);
	while (tmp_a)
	{
		head_a = tmp_a;
		tmp_a = head_a->next;
		free(head_a);
	}
	if (head_b == NULL)
		return ;
	tmp_b = head_b->next;
	free(head_b);
	while (tmp_b)
	{
		head_b = tmp_b;
		tmp_b = head_b->next;
		free(head_b);
	}
}

long long int	ft_atol(const char *nptr)
{
	long long int	i;
	long long int	sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i + 1] == '+' || nptr[i + 1] == '-')
			return (0);
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
