/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/09 19:44:16 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**** INCLUDE A supprimer ****/ // ! a supprimer
# include <stdio.h>
# include <stdlib.h>


/* ************************************************************************** */
/*							      	 INCLUDE							      */
/* ************************************************************************** */

# include "libft.h"



/* ************************************************************************** */
/*							      	 STRUCTURE							      */
/* ************************************************************************** */

typedef struct s_list
{
	struct s_list	*pile_a;
	struct s_list	*pile_b;
	int				content;
	struct s_list	*next;
}	t_list;


/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
list.c
*************/
t_list	*ft_create_node(int data);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *node);
void	ft_lstadd_back(t_list **list, t_list *last_node);
t_list	*ft_lstlast(t_list *node);
void	ft_free(t_list *head);



/*************
main.c
*************/
void	print_swap(char *instruction);
void	print_list(t_list *node);
void	ft_check_parameter(int ac);
void	ft_message_error();

/*************
push.c
*************/


/*************
push_swap.c
*************/
void	ft_init(t_list *structure);


/*************
reverse_rotate.c
*************/



/*************
swap.c
*************/
void	ft_swap_a(t_list *structure);



/*************
utils.c
*************/




#endif