#ifndef PUSH_SWAP
# define PUSH_SWAP

t_stack			*argument_read(int ac, char **av);
t_stack			*stack_init(int id, int lenght, int mid, int debug);
void			stack_free(t_stack **a);

void			push(t_stack *a, t_stack *b);
void			swap(t_stack *a, t_stack *b);
void			rotate(t_stack *a, t_stack *b);
void			rotate_rev(t_stack *a, t_stack *b);

void			push_swap(t_stack *a, t_stack *b);

void			stack_print(t_stack a, t_stack b);

int				is_previous(t_stack *a, t_stack *b, int sub, int main);

#endif
