/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/13 15:01:05 by gpeta            ###   ########.fr       */
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
	int				index;
	struct s_list	*next;
} 					t_list;

// typedef struct s_list t_list;


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


/*************
push.c
*************/


/*************
push_swap.c
*************/
// void	ft_init(t_list **structure, int ac);
t_list	*ft_linked_list(int ac, char **av);


/*************
reverse_rotate.c
*************/
void	ft_rra_reverse_rotate_a(t_list **list);
void	ft_rrb_reverse_rotate_b(t_list **list);
void	ft_rrr_reverse_rotate_a_b(t_list **list);


/*************
rotate.c
*************/
void	ft_ra_rotate_a(t_list **head);
void	ft_rb_rotate_b(t_list **head);
void	ft_rr_rotate_a_b(t_list **head);



/*************
swap.c
*************/
void	ft_sa_swap_a(t_list **structure);
void	ft_sb_swap_b(t_list **structure);
void	ft_ss_swap_a_b(t_list **head);



/*************
utils.c
*************/
void	print_swap(char *instruction);
void	print_list(t_list *node);
// void	print_list(t_list **node);
void	ft_check_parameter(int ac, char **av);
void	ft_message_error();
void	print_ac_i(int i, int ac);




#endif