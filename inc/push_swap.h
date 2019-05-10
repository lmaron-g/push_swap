#ifndef PUSH_SWAP
# define PUSH_SWAP


#define PUSH_BACK (is_previous(a, b, a->stack[a->lenght - 1], b->stack[0]) || \
						b->stack[0] == a->min)

#define SORT_PART (is_previous(a, b, a->stack[a->lenght - 1], a->stack[0]) || \
				a->stack[0] == a->min && !is_sorted(a))

t_stack			*argument_read(int ac, char **av);
t_stack			*stack_init(int id, int lenght, int mid, int debug);
void			stack_free(t_stack **a);

void			push(t_stack *a, t_stack *b);
void			swap(t_stack *a, t_stack *b);
void			rotate(t_stack *a, t_stack *b);
void			rotate_rev(t_stack *a, t_stack *b);

void			push_swap(t_stack *a, t_stack *b);
void			sort_three(t_stack *a, t_stack *b);




void			stack_print(t_stack a, t_stack b);

int				is_previous(t_stack *a, t_stack *b, int sub, int main);

#endif
