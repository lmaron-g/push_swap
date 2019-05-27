#include "libft.h"
#include "push_swap.h"

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac > 1)
	{
		a = argument_read(ac, av, 0);
		b = stack_init('b', 0, 0, 0);
		push_swap(a, b);
		stack_free(&a);
	}
	else
		print_error(ERR_PUSH_USAGE);
	return 0;
}