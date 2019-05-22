#include "checker.h"
#include "push_swap.h"
#include "libft.h"
#include "mlx.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_fdf	*fdf;

	if (ac > 1)
	{
		errno = 0;
		a = argument_read(ac, av, 1);
		b = stack_init('b', 0, 0, a->debug);
		if (a->debug == 2)
		{
			fdf = fdf_init(a, b);
			mlx_hook(fdf->win, 17, 0, close_win, fdf);
			mlx_loop_hook(fdf->mlx, visual_check, fdf);
		}
		else
			checker(a, b, fdf);
	}
	else
		print_error(ERR_CHECKER_USAGE);
	return 0;
}
