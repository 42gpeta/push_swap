/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/01 18:38:01 by glodi            ###   ########.fr       */
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

# define INT_MIN -2147483648
# define INT_MAX 2147483647

/* ************************************************************************** */
/*							      	 STRUCTURE							      */
/* ************************************************************************** */

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
} 					t_list;

/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
algo.c
*************/
int		ft_pre_sort(t_list **head_a, t_list **head_b, int size);
void	ft_sort(t_list **head_a, t_list **head_b);
void	ft_leave_three_biggest_in_a(t_list **head_a, t_list **head_b, int max_size, int size);
void	ft_put_index_one_on_top(t_list **head_a);

/*************
algo_utils_conbination.c
*************/
int		ft_choose_best_combination(t_list **head_a, t_list **head_b);
void	ft_execute_best_combination(t_list **head_a, t_list **head_b, int index);

/*************
algo_utils_count.c
*************/
void	ft_nearest_index_for_B_node(t_list **head_a, t_list **head_b);
void	ft_count_rb_and_rrb(t_list **head_b);

/*************
algo_utils_execute.c
*************/
void	ft_execute_ra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_execute_ra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_execute_rra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_execute_rra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index);

/*************
algo_utils_find_node.c
*************/
t_list	*ft_find_node_with_cheapest_ra_rb_shoot(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_with_cheapest_ra_rrb_shoot(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_with_cheapest_rra_rb_shoot(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_with_cheapest_rra_rrb_shoot(t_list **head_a, t_list **head_b);

/*************
error.c
*************/
void	ft_check_parameter(int ac, t_list **head_a, t_list **head_b);
void	ft_check_args(char **av, t_list **head_a, t_list **head_b);
int		ft_arg_is_available_number(char *str);
void	ft_check_doublon(t_list **head_a, t_list **head_b, char **av);

// void	ft_message_error(t_list **head_a, t_list **head_b);  // TODO version finale
void	ft_message_error(t_list **head_a, t_list **head_b, char *message); // ! a supprimer



/*************
list.c
*************/

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *node);
int		ft_lstadd_back(t_list **list, t_list *last_node); // ? v2
t_list	*ft_lstlast(t_list *node);
int		ft_lstsize(t_list *head);

/*************
list_utils.c
*************/
t_list	*ft_create_node(int data);
void	ft_free(t_list *head_a, t_list *head_b);
long long int	ft_atol(const char *nptr);

/*************
main.c
*************/

/*************
print.c // ! a supprimer
*************/
void	ft_print_swap(char *instruction);
void	print_list(t_list *node, char letter);
void	print_list_size(t_list *head);
void	print_ac_i(int i, int ac);

/*************
push.c
*************/
void	ft_pa_push_a(t_list **head_a, t_list **head_b, char *instruction);
void	ft_pb_push_b(t_list **head_a, t_list **head_b, char *instruction);

/*************
push_swap.c
*************/
t_list	*ft_linked_list(int ac, char **av, t_list **head_a, t_list **head_b);
void	ft_index(t_list **head);

/*************
reverse_rotate.c
*************/
void	ft_rra_reverse_rotate_a(t_list **head_a, char *instruction);
void	ft_rrb_reverse_rotate_b(t_list **head_b, char *instruction);
void	ft_rrr_reverse_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction);

/*************
rotate.c
*************/
void	ft_ra_rotate_a(t_list **head_a, char *instruction);
void	ft_rb_rotate_b(t_list **head_b, char *instruction);
void	ft_rr_rotate_a_b(t_list **head_a, t_list **head_b, char *instruction);

/*************
sort.c
*************/
void	ft_sort_five_node(t_list **head_a, t_list **head_b); // ? v1
void	ft_sort_four_node(t_list **head_a, t_list **head_b);
void	ft_sort_tree_node(t_list **head_a);
void	ft_sort_two_node(t_list **head_a);
int		ft_is_sorted(t_list **head_a);

/*************
swap.c
*************/
void	ft_sa_swap_a(t_list **head_a, char *instruction);
void	ft_sb_swap_b(t_list **head_b, char *instruction);
void	ft_ss_swap_a_b(t_list **head_a, t_list **head_b, char *instruction);

#endif