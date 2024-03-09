#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h> // To use bool flags
# include <limits.h> // to define MAX and MIN macros
# include <stdio.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int			nbr;
	int			index;
	int			push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

int	main(int argc, char **argv);
int	error_syntax(char *str);
int	error_duplicate(t_stack_node *a, int n);
void	free_errors(t_stack_node **a);
void	free_stack(t_stack_node **stack);
void	init_nodes_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
void	set_target_a(t_stack_node *a, t_stack_node *b);
void	cost_analysis_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *stack);
void	init_nodes_b(t_stack_node *a, t_stack_node *b);
void	set_target_b(t_stack_node *a, t_stack_node *b);
void	push(t_stack_node **dst, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **b, t_stack_node **a, bool print);
void	rev_rotate(t_stack_node **stack);
void	rra(t_stack_node **a, bool print);
void	rrb(t_stack_node **b, bool print);
void	rrr(t_stack_node **a, t_stack_node **b, bool print);
void     rotate(t_stack_node **stack);
void	ra(t_stack_node **a, bool print);
void	rb(t_stack_node **b, bool print);
void	rr(t_stack_node **a, t_stack_node **b, bool print);
void	sort_stacks(t_stack_node **a, t_stack_node **b);
void	move_a_to_b(t_stack_node **a, t_stack_node **b);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void	min_on_top(t_stack_node **a);
void	sort_three(t_stack_node **a);
void    init_stack_a(t_stack_node **a, char **argv);
long     ft_atol(const char *s);
void	append_node(t_stack_node **stack, int n);
t_stack_node	*get_cheapest(t_stack_node *stack);
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
bool	stack_sorted(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void	swap(t_stack_node **head);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
t_stack_node	*find_min(t_stack_node *stack);
int	ft_words(char *s, char c);
int	ft_word_len(char *s, char i);
char	**ft_split(char *s, char c);
t_stack_node	*find_last(t_stack_node *stack);
int	ft_isdigit(int i);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
void	*ft_memcpy(void *dest, void *src, size_t n);

#endif
