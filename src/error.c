/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:15:34 by gpeta             #+#    #+#             */
/*   Updated: 2023/06/30 18:14:30 by glodi            ###   ########.fr       */
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

int	ft_arg_is_available_number(char *str)
{
	long long int nbr;

	nbr = ft_atol(str);

	if (INT_MIN < nbr && nbr < INT_MAX)
	{
		printf("atol de %s:%lld\n", str, nbr);
		return (1);
	}
	return (0);
}

/* void	ft_check_doublon(char **av, int len_tab) // TODO a faire pour controler les doublons
{
	char doublon[len_tab];

	while (av)
	{
		if (av[i] == doublon[j])
			
			
	}
} */


void	ft_check_args(char **av, t_list **head_a, t_list **head_b)
{
	int	i;
	int	j;
	long long int	arg;
	
/* 	int len_args;

	len_args = 1;
	while (av[len_args])
		len_args++;
	printf("len_args = %d\n", len_args);

	if (ft_check_doublon() == 0)
		ft_message_error(head_a, head_b, "ft_check_args : presence d'un doublon"); */
		
	
	i = 1;
	
	while (av[i])
	{
/* 		if (av[i] == 34)
			printf("erreur \"\"\n"); */
		
		if (ft_arg_is_available_number(av[i]) != 1)
			ft_message_error(head_a, head_b, "ft_check_args : > ou < aux INT définis");
		
		j = 0;
		if (av[i][j] == '-')
			j++;
		if (av[i][j] == NULL /* && av[i][j+1] == 34 */)
			ft_message_error(head_a, head_b, "ft_check_args : c'est une combi de \"\"");
		
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				ft_message_error(head_a, head_b, "ft_check_args : c'est pas un chiffre");
			j++;
		}
			
		// arg = ft_atol(av[i]);
		// if (av[i] == 0)
		// {
		// 	printf("av = 0\n");
		// 	i++;
		// }
		
		// if (!arg)
		// {
		// 	printf("arret sur %s\n", av[i]);
		// 	ft_message_error(head_a, head_b, "ft_check_args : ATOI fail");
		// }	
			// ft_message_error(head_a, head_b);
		// if (ft_isprint(ft_atoi(av[i][0])) == 1)
		// 	ft_message_error(head_a, head_b, "ft_check_args : not a number");
		// 	// ft_message_error(head_a, head_b);
		// printf("char|int %s|%lld\n", av[i], arg); // ! a supprimer
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