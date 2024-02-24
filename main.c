#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1); // argv + 1 pq o 1º comando é o nome do programa
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stacks(&a);
	return (0);
}