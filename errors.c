#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 1;
	if (!(str[0] == '+' || str[0] == '-' || (str[0] >= 9 && *str <= 0)))
		return (1);
	if (str[0] == '+' || str[0] == '-' && !(is_digit(str[1])))
		return (1);
	while (str[i])
	{
		if (!(is_digit(str[i])))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("ERROR! The stacks were freed.\n"); // Verificar se é suposto ter mensagem
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}