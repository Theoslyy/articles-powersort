#include "definitions.h"

struct Run pop(struct C_Bounded_Stack bounded_stack)
{
    if (bounded_stack.size == 0) return; 
    bounded_stack.size = bounded_stack.size - 1;
    int r = bounded_stack.top; 
    if(bounded_stack.top == 0) bounded_stack.top = bounded_stack.MaxSize - 1; 
    else bounded_stack.top = bounded_stack.top - 1; 
    return bounded_stack.stack[r];
}
void push(struct C_Bounded_Stack bounded_stack, int bound, int pow)
{
    // Do I need to ensure the stack is allocated in memory before a push?
    //bound is the boundary of the run s_1...e_1
    //p is the node power between this run and the run s_2....e_2
    bounded_stack.top = bounded_stack.top + 1;
    if(bounded_stack.top > bounded_stack.MaxSize) bounded_stack.top = 0; 
    if(bounded_stack.size < bounded_stack.MaxSize) bounded_stack.size = bounded_stack.size + 1; 
    //struct Run r; r.boundary = bound; r.power = pow; 
    bounded_stack.stack[bounded_stack.top].boundary = bound;
    bounded_stack.stack[bounded_stack.top].power = pow;
}
int topPower(struct C_Bounded_Stack bounded_stack)
{
    return bounded_stack.stack[bounded_stack.top].power;
}

int ExtendRunRight(int start, int end)
{
    return -1;
}
int ExtendRunLeft(int start, int end)
{
    return -1;
}
void Merge(void* A, int s0, int s1, int e1){
    return; 
}