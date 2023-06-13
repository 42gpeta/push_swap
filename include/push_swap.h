/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/06/13 18:46:24 by gpeta            ###   ########.fr       */
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
	// struct s_list	*pile_a;
	// struct s_list	*pile_b;
	int				content;
	int				index;
	int				cost;
	struct s_list	*next;
} 					t_list;

// typedef struct s_list t_list;


/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
error.c
*************/
// void	ft_check_parameter(int ac, char **av);
void	ft_check_parameter(int ac, char **av, t_list **head_a, t_list **head_b);
// void	ft_check_parameter(int ac, t_list **head_a, t_list **head_b);

// void	ft_check_doublon(); // TODO a faire pour controler les doublons


// void	ft_check_args(char **av);
void	ft_check_args(char **av, t_list **head_a, t_list **head_b);

// void	ft_message_error(t_list **head_a, t_list **head_b);  // TODO version finale
void	ft_message_error(t_list **head_a, t_list **head_b, char *message); // ! a supprimer

/*************
list.c
*************/
t_list	*ft_create_node(int data);

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *node);
void	ft_lstadd_back(t_list **list, t_list *last_node);
t_list	*ft_lstlast(t_list *node);
// void	ft_free(t_list **head_a, t_list **head_b); // ? v3
void	ft_free(t_list *head_a, t_list *head_b); // ? v2
// void	ft_free(t_list *head_a);
int		ft_lstsize(t_list *head);



/*************
main.c
*************/



/*************
print.c
*************/
void	print_swap(char *instruction);
void	print_list(t_list *node, char letter);
// void	print_list(t_list **node);
void	print_list_size(t_list *head);
void	print_ac_i(int i, int ac);


/*************
push.c
*************/
void	ft_pa_push_a(t_list **head_a, t_list **head_b, char *instruction);
void	ft_pb_push_b(t_list **head_a, t_list **head_b, char *instruction);


/*************
radix.c
*************/
int	ft_find_max(t_list **head_a);
int	ft_find_index_max_bit(int index_max);
// void	ft_radix(t_list **head_a, t_list **head_b);
void	ft_radix(t_list **head_a);



/*************
push_swap.c
*************/
// void	ft_init(t_list **structure, int ac);
// t_list	*ft_linked_list(int ac, char **av);
t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b);
void	ft_index(t_list **head);
void	ft_list_a_five_node(t_list **head_a, t_list **head_b); // ? v1
void	ft_list_a_four_node(t_list **head_a, t_list **head_b);
// void	ft_list_a_four_node(t_list **head_a);
void	ft_push_list_b_to_list_a(t_list **head_a, t_list **head_b);
// void	ft_list_a_tree_node(t_list *head_a);
void	ft_list_a_tree_node(t_list **head_a);
void	ft_list_a_two_node(t_list **head_a);




/*************
reverse_rotate.c
*************/
// void	ft_rra_reverse_rotate_a(t_list **head_a, t_list **head_b, char *instruction);
// void	ft_rrb_reverse_rotate_b(t_list **head_a, t_list **head_b, char *instruction);
void	ft_rra_reverse_rotate_a(t_list **head_a, char *instruction);
void	ft_rrb_reverse_rotate_b(t_list **head_b, char *instruction);
void	ft_rrr_reverse_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction);


/*************
rotate.c
*************/
// void	ft_ra_rotate_a(t_list **head_a, t_list **head_b, char *instruction);
// void	ft_rb_rotate_b(t_list **head_a, t_list **head_b, char *instruction);
void	ft_ra_rotate_a(t_list **head_a, char *instruction);
void	ft_rb_rotate_b(t_list **head_b, char *instruction);
void	ft_rr_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction);



/*************
swap.c
*************/
// void	ft_sa_swap_a(t_list **head_a, t_list **head_b, char *instruction);
// void	ft_sb_swap_b(t_list **head_a, t_list **head_b, char *instruction);
void	ft_sa_swap_a(t_list **head_a, char *instruction);
void	ft_sb_swap_b(t_list **head_b, char *instruction);
void	ft_ss_swap_a_b(t_list **head_a, t_list **head_b, char *instruction);

/*************
turkish.c
*************/
int	ft_list_a_min(t_list **head_a, t_list **head_b);
int	ft_list_b_min(t_list **head_a, t_list **head_b);
int	ft_list_a_max(t_list **head_a, t_list **head_b);
int	ft_list_b_max(t_list **head_a, t_list **head_b);

void ft_find_cost(t_list **head_a, t_list **head_b);
int	ft_cheapest_number(t_list **head_a, t_list **head_b);




#endif