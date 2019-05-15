#include "mlx.h"
#include "checker.h"
#include "libft.h"

t_fdf		*fdf_init(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		print_error(ERR_FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		print_error(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Push_Swap")))
		print_error(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		print_error(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
										&(fdf->size_line), &(fdf->endian));
	return (fdf);
}
