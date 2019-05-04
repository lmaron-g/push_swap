#ifndef PUSH_SWAP
# define PUSH_SWAP

#define ERR_PUSH_USAGE "Usage: ./push_swap [-v] [STACK]"
#define ERR_STACK_INIT "Initialization error: stack_init();"
#define ERR_INVALID "Invalid stack"

t_stack			*argument_read(int ac, char **av);
t_stack			*stack_init(int id, int lenght, int mid, int debug);
void			stack_free(t_stack **a);

void			push(t_stack *a, t_stack *b);
void			swap(t_stack *a, t_stack *b);
void			rotate(t_stack *a, t_stack *b);
void			rotate_rev(t_stack *a, t_stack *b);

void	        push_swap(t_stack *a, t_stack *b, int left, int right);

void			stack_print(t_stack a, t_stack b);

#endif
