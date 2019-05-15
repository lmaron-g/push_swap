#ifndef PUSH_SWAP
# define PUSH_SWAP

#include "libft.h"

#define LAST lenght - 1

#define PUSH_BACK (is_previous(a, b, a->stack[a->lenght - 1], b->stack[0]) || \
						b->stack[0] == a->min)

#define SORT_PART (is_previous(a, b, a->stack[a->lenght - 1], a->stack[0]) || \
				a->stack[0] == a->min && !is_sorted(a, b))

t_stack			*argument_read(int ac, char **av);

void			push(t_stack *a, t_stack *b);
void			swap(t_stack *a);
void			rotate(t_stack *a);
void			rotate_rev(t_stack *a);

void			push_swap(t_stack *a, t_stack *b);
void			sort_three(t_stack *a, int order);
void			half_to_b(t_stack *a, t_stack *b);
void			half_to_a(t_stack *a, t_stack *b);
void			part_to_b(t_stack *a, t_stack *b, int divider);
void			return_back(t_stack *a, t_stack *b);

void			like_selection_sort(t_stack *a, t_stack *b);
void			stack_print(t_stack a, t_stack b);
int				is_previous(t_stack *a, t_stack *b, int sub, int main);

#endif
