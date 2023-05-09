/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:27:09 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/09 19:52:08 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list *structure)
{
	t_list	tmp;
	
	tmp = structure->pile_a->next;
	structure->pile_a->next = structure->pile_a->next->next;
	structure->pile_a->next->next = tmp;
	
}