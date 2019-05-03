#include "checker.h"
#include "push_swap.h"
#include "libft.h"

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac > 1)
	{
		a = argument_read(ac, av);
		b = stack_init(1, 0, 0, a->debug);
		checker(&a, &b);
		stack_print(*a, *b);
		is_sort(a, b);
	}
	else
		print_error(ERR_CHECKER_USAGE);
	return 0;
}
