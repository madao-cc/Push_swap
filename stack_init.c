#include "push_swap.h"

void    init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int	i;

	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

long     ft_atol(const char *s)
{
	long	result;
	bool	is_positive;
	int	i;

	i = 0;
	result = 0;
	is_positive = true;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r' || s[i] == '\f' || s[i] == '\v')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			is_positive = false;
			i++;
		}
	}
	while (ft_isdigit(s[i]))
		result = result * 10 + (s[i++] - '0');
	if (is_positive == true)
		return (result);
	return (result * -1);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	last_node = find_last(*stack); //procurar o ultimo node
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL; // para ja vai ser o ultimo da lista
	node->nbr = n;
	if (!(*stack)) // stack está vazia
	{
		*stack = node; // fazer deste node a cabeca da lista
		node->prev = NULL;
	}
	else // se não está vazia, ja existem nodes
	{
		last_node->next = node; //adicionar o novo node a seguir ao que já existia
		node->prev = last_node; //update novo node
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
