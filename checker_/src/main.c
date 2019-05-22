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

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == 53)
		exit(0);
	if (key == 18)
		visual_check(fdf);
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
			mlx_hook(fdf->win, 2, 0, key_press, fdf);
			mlx_loop(fdf->mlx);
		}
		else
			checker(a, b);
	}
	else
		print_error(ERR_CHECKER_USAGE);
	return 0;
}
