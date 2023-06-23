/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:34 by gpeta             #+#    #+#             */
/*   Updated: 2023/06/23 16:58:55 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_check_parameter(int ac, char **av, t_list **head_a, t_list **head_b)
void	ft_check_parameter(int ac, t_list **head_a, t_list **head_b)
{
	if (ac < 2)
		ft_message_error(head_a, head_b, "ft_check_parameter : ac < 2");
		// ft_message_error(head_a, head_b);
	// if (!av[2])
	// 	ft_message_error(head_a, head_b, "ft_check_parameter : av[2] doesn't exist"); // ! a remettre
		// ft_message_error(head_a, head_b);

}

// void	ft_check_doublon() // TODO a faire pour controler les doublons

void	ft_check_args(char **av, t_list **head_a, t_list **head_b)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!(ft_atoi(av[i])))
			ft_message_error(head_a, head_b, "ft_check_args : ATOI fail");
		// ft_message_error(head_a, head_b);

		i++;
	}
}

// void	ft_message_error(t_list **head_a, t_list **head_b) // TODO version finale
void	ft_message_error(t_list **head_a, t_list **head_b, char *message) // TODO version pour dev
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message)); // ! a supprimer
	write(1, "\n", 1); // ! a supprimer
	ft_free(*head_a, *head_b);
	exit(EXIT_FAILURE);
}