#include "push_swap.h"

void    sort_first_two(t_greedy **stack_b)
{
    if ((*stack_b)->value < (*stack_b)->next->value)
        rb(stack_b);
}
