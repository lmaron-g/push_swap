#include "libft.h"
#include "checker.h"
#include "mlx.h"

static void	plot(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static void	print_value(t_fdf *fdf, t_stack *a, int val, int i)
{
	int		x;
	int		y;
	int		end;
	int		color;
	int		block_h;
	
	color = val < 0 ? NVAL : VAL;
	val == 0 ? val++ : 0;
	val *= val < 0 ? -1 : 1;
	val *= fdf->zoom_x;
	y = HEIGHT - (i * fdf->zoom_y);
	block_h = fdf->zoom_y;
	while (block_h-- && --y)
	{
		x = ((WIDTH / 2) - val) / 2;
		if (a->id == 'b')
			x += WIDTH / 2;
		end = x + val;
		while (x < end)
			plot(fdf, x++, y, color);
	}
}

static void	setup_background(t_fdf *fdf)
{
	int		i;
	int		*image;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < (WIDTH / 2)) ? LEFT_STACK : RIGHT_STACK;
		i++;
	}
}

void		vizualize(t_fdf *fdf, t_stack *a, t_stack *b)
{
	int		i;
	
	i = FT_MAX(a->lenght, b->lenght) - 1;
	setup_background(fdf);
	while (i >= 0)
	{
		if (i < a->lenght)
			print_value(fdf, a, a->stack[i], a->lenght - i - 1);
		if (i < b->lenght)		
			print_value(fdf, b, b->stack[i], b->lenght - i - 1);
		i--;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

t_fdf		*fdf_init(t_stack *a, t_stack *b)
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
	fdf->zoom_x = (WIDTH / 2) / a->max;	
	fdf->zoom_y = HEIGHT / a->lenght;
	fdf->a = a;
	fdf->b = b;
	return (fdf);
}