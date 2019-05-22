#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"
#include "libft.h"

#define WIDTH 1000
#define HEIGHT 800

#define CHECKER_INVAL "ERROR"
#define ERR_CHECKER_USAGE "Usage: ./checker [-v] [STACK]"

# define ERR_FDF_INIT		"Initialization error"

#define LEFT_STACK 0xF9FE37
#define RIGHT_STACK 0xFFB838

#define VAL 0x2DCE69
#define NVAL 0x50DF85

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			zoom_x;
	int			zoom_y;
	t_stack		*a;
	t_stack		*b;
}				t_fdf;

t_fdf		*fdf_init(t_stack *a, t_stack *b);

int			visual_check(void *fdf);
void		checker(t_stack *a, t_stack *b, t_fdf *fdf);
void		vizualize(t_fdf *fdf, t_stack *a, t_stack *b);

#endif