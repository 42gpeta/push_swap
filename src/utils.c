/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:28:42 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/13 13:23:29 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_swap(char *instruction)
{

	if (ft_strncmp(instruction, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(instruction, "sb", 2) == 0)
		write(1, "sb\n", 3);
	else if (ft_strncmp(instruction, "ss", 2) == 0)
		write(1, "ss\n", 3);
	else if (ft_strncmp(instruction, "pa", 2) == 0)
		write(1, "pa\n", 3);	
	else if (ft_strncmp(instruction, "pb", 2) == 0)
		write(1, "pb\n", 3);
	else if (ft_strncmp(instruction, "ra", 2) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(instruction, "rb", 2) == 0)
		write(1, "rb\n", 3);
	else if (ft_strncmp(instruction, "rr", 2) == 0)
		write(1, "rr\n", 3);
	else if (ft_strncmp(instruction, "rra", 3) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(instruction, "rrb", 3) == 0)
		write(1, "rrb\n", 4);
	else if (ft_strncmp(instruction, "rrr", 3) == 0)
		write(1, "rrr\n", 4);
		
}

void	print_list(t_list *node)
{
	t_list	*tmp;

	tmp = node;
	while (tmp != NULL)
	{
		ft_printf("%d -> ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_check_parameter(int ac, char **av)
{
	if (ac < 2)
		ft_message_error();
	if (!av[2])
		ft_message_error();

}

void	ft_message_error()
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_ac_i(int i, int ac)
{
	printf("ac = %d\n i = %d\n", ac, i);
}