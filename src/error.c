/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:34 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 18:58:17 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_parameter(int ac, t_list **head_a, t_list **head_b) // TODO ajouter dans le main en faisant un exit propre : sans rien envoyer
{
	if (ac < 2)
		ft_message_error(head_a, head_b, "ft_check_parameter : ac < 2");
		// ft_message_error(head_a, head_b);
}

int	ft_arg_is_available_number(char *str)
{
	long long int nbr;

	nbr = ft_atol(str);
	if (INT_MIN < nbr && nbr < INT_MAX)
		return (1);
	return (0);
}

void	ft_check_doublon(t_list **head_a, t_list **head_b, char **av) // TODO a faire pour controler les doublons
{
	int i;
	int j;
	
	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strlen(av[i]) == ft_strlen(av[j]) && ft_strncmp(av[i],av[j],ft_strlen(av[i])) == 0)
				ft_message_error(head_a, head_b, "ft_check_doublon : doublon");
				// ft_message_error(head_a, head_b);
			j++;
		}
		i++;
	}
}


void	ft_check_args(char **av, t_list **head_a, t_list **head_b)
{
	int	i;
	int	j;
	long long int	arg;
	
	ft_check_doublon(head_a, head_b, av);
	i = 1;
	while (av[i])
	{
		if (ft_arg_is_available_number(av[i]) != 1)
			ft_message_error(head_a, head_b, "ft_check_args : > ou < aux INT définis");
			// ft_message_error(head_a, head_b);
		j = 0;
		if (av[i][j] == '-')
			j++;
		if (av[i][j] == 0)
		{
			// printf("av[%d] = %s\n", i, av[i]); // ! a supprimer
			ft_message_error(head_a, head_b, "ft_check_args : c'est une combi de \"\"");
			// ft_message_error(head_a, head_b);
		}
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				ft_message_error(head_a, head_b, "ft_check_args : c'est pas un chiffre");
				// ft_message_error(head_a, head_b);
			j++;
		}
		i++;
	}
}

// void	ft_message_error(t_list **head_a, t_list **head_b) // TODO version finale
void	ft_message_error(t_list **head_a, t_list **head_b, char *message) // TODO version pour dev
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message)); // ! a supprimer
	write(2, "\n", 1); // ! a supprimer
	ft_free(*head_a, *head_b);
	exit(EXIT_FAILURE);
}
