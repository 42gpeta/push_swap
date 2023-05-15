/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:34 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/15 18:24:55 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_parameter(int ac, char **av)
{
	if (ac < 2)
		ft_message_error("ft_check_parameter : ac < 2");
		// ft_message_error();
	if (!av[2])
		ft_message_error("ft_check_parameter : av[2] doesn't exist");
		// ft_message_error();

}

void	ft_check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!(ft_atoi(av[i])))
			ft_message_error("ft_check_args : ATOI fail");
		i++;
	}
}

// void	ft_message_error() // TODO version finale
void	ft_message_error(char *message) // TODO version pour dev
{
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message)); // ! a supprimer
	write(1, "\n", 1); // ! a supprimer
	exit(EXIT_FAILURE);
}