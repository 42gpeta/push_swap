/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:13:57 by gpeta             #+#    #+#             */
/*   Updated: 2023/07/04 14:52:28 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/*							      	 INCLUDE							      */
/* ************************************************************************** */

# include "libft.h"
# include "push_swap_utils.h"

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
}					t_list;

/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
algo.c
*************/
int		ft_pre_sort(t_list **head_a, t_list **head_b, int size);
void	ft_sort(t_list **head_a, t_list **head_b);
void	ft_leave_3_biggest(t_list **h_a, t_list **h_b, int max_i, int size);
void	ft_put_index_one_on_top(t_list **head_a);

/*************
algo_utils_conbination.c
*************/
int		ft_choose_best_combination(t_list **head_a, t_list **head_b);
void	ft_exe_best_combination(t_list **head_a, t_list **head_b, int index);

/*************
algo_utils_count.c
*************/
void	ft_nearest_index_for_b_node(t_list **head_a, t_list **head_b);
void	ft_count_rb_and_rrb(t_list **head_b);

/*************
algo_utils_execute.c
*************/
void	ft_exe_ra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_exe_ra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_exe_rra_rb(t_list **head_a, t_list **head_b, t_list *nearest_index);
void	ft_exe_rra_rrb(t_list **head_a, t_list **head_b, t_list *nearest_index);

/*************
algo_utils_find_node.c
*************/
t_list	*ft_find_node_w_cheapest_ra_rb(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_w_cheapest_ra_rrb(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_w_cheapest_rra_rb(t_list **head_a, t_list **head_b);
t_list	*ft_find_node_w_cheapest_rra_rrb(t_list **head_a, t_list **head_b);

/*************
error.c
*************/
void	ft_is_enough_parameter(int ac);
void	ft_check_args(char **av, t_list **head_a, t_list **head_b);
int		ft_arg_is_available_number(char *str);
void	ft_check_doublon(t_list **head_a, t_list **head_b, char **av);
void	ft_message_error(t_list **head_a, t_list **head_b);

/*************
list.c
*************/

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **list, t_list *node);
int		ft_lstadd_back(t_list **list, t_list *last_node);
t_list	*ft_lstlast(t_list *node);
int		ft_lstsize(t_list *head);

/*************
list_utils.c
*************/
void	ft_free(t_list *head_a, t_list *head_b);

/*************
print.c
*************/
void	ft_print_swap(char *instruction);

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
void	ft_rrr_reverse_rotate(t_list **h_a, t_list **h_b, char *instruction);

/*************
rotate.c
*************/
void	ft_ra_rotate_a(t_list **head_a, char *instruction);
void	ft_rb_rotate_b(t_list **head_b, char *instruction);
void	ft_rr_rotate(t_list **head_a, t_list **head_b, char *instruction);

/*************
sort.c
*************/
void	ft_sort_five_node(t_list **head_a, t_list **head_b);
void	ft_sort_four_node(t_list **head_a, t_list **head_b);
void	ft_sort_tree_node(t_list **head_a);
void	ft_sort_two_node(t_list **head_a);
int		ft_is_sorted(t_list **head_a);

/*************
sort_utils.c
*************/
void	ft_inf_sup(t_list **head_a);
void	ft_sup_inf(t_list **head_a);
void	ft_sup_sup(t_list **head_a);

/*************
swap.c
*************/
void	ft_sa_swap_a(t_list **head_a, char *instruction);
void	ft_sb_swap_b(t_list **head_b, char *instruction);
void	ft_ss_swap(t_list **head_a, t_list **head_b, char *instruction);

#endif