#pragma once 
#include "definitions.h"

// NODE POWER:
int nodepower(int s1, int s2)
{
    return __builtin_clz(s1 ^ s2);
}

// SORTING:

// For comparison -
// the qsort header is:
// heapsort_r (void *base, size_t n, size_t size, __compar_d_fn_t cmp, void *arg)
// a.k.a array, size of the array, size of the types in the array, comparison function, comparison argument. 

// Question: What will our C be? -> Tests. 
// This definition is still not generic, its for ints: 
void c_bounded_powersort(void *array, int n, int C) // missing: size_t n, size_t size, comp function, comp arg
{ 
    struct C_Bounded_Stack bounded_stack;     
    bounded_stack.MaxSize = C; bounded_stack.stack = malloc(bounded_stack.MaxSize * sizeof(struct Run));
    int s0;
    int s1 = 1; int e1 = ExtendRunRight(s1, n); //(1, n), we're using (s1, n) just to keep the pattern
    int s2; int e2; int p; 
    while(1)
    {
        while (e1 < n)
        {
            s2 = e1 + 1; e2 = ExtendRunRight(s2, n); // s2 is not necessary, but we're keeping it for readability. 
            p = nodepower(s1, s2);
            while(bounded_stack.size > 1 && (topPower(bounded_stack) > p))
            {
                s0 = pop(bounded_stack).boundary;
                Merge(array, s0, s1, e1);
                s1 = s0;
            }
            push(bounded_stack, s1, p);
            s1 = s2; e1 = e2;
        }
        while (bounded_stack.size > 1){
            s0 = pop(bounded_stack).boundary;
            Merge(array, s0, s1, e1);
            s1 = s0;
        }
        s1 = pop(bounded_stack).boundary;
        s0 = s1; s1 = e1; e1 = s0; 
        if(e1 == 1) break; 
        while(e1 > 1)
        {
            s2 = e1 + 1; e2 = ExtendRunLeft(s2, 1); 
            p = nodepower(s1, s2);
            while(bounded_stack.size > 1 && (topPower(bounded_stack) > p))
            {
                s0 = pop(bounded_stack).boundary;
                Merge(array, s0, s1, e1);
                s1 = s0;
            }
            push(bounded_stack, s1, p);
            s1 = s2; e1 = e2;
        }
        while (bounded_stack.size > 1){
            s0 = pop(bounded_stack).boundary;
            Merge(array, s0, s1, e1);
            s1 = s0;
        } 
        s1 = pop(bounded_stack).boundary;
        s0 = s1; s1 = e1; e1 = s0; 
        if(e1 == n) break;
    }
}