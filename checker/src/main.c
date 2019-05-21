#include "checker.h"
#include "push_swap.h"
#include "libft.h"
#include "mlx.h"

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_fdf	*fdf;

	if (ac > 1)
	{
		errno = 0;
		a = argument_read(ac, av);
		b = stack_init('b', 0, 0, (a->debug = 1));
		fdf = fdf_init(a);
		checker(a, b, fdf);
		vizualize(fdf, a, b);
		mlx_loop(fdf->mlx);
	}
	else
		print_error(ERR_CHECKER_USAGE);
	return 0;
}
