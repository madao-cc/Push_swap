#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h> // To use bool flags
# include <limits.h> // to define MAX and MIN macros
# include "../Libft/libft.h"
// # include "../ft_printf/ft_printf.h"

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

#endif