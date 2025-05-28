#ifndef DEFINITIONS_H
#define DEFINITIONS_H
struct Run
{
    int boundary;
    int power;
};
struct C_Bounded_Stack
{
    int top; int size; int MaxSize;
    struct Run* stack; // bounded_stack.MaxSize = C; bounded_stack.stack = malloc(bounded_stack.MaxSize * sizeof(struct Run));
};

struct Run pop(struct C_Bounded_Stack bounded_stack);
void push(struct C_Bounded_Stack bounded_stack, int bound, int pow);
int topPower(struct C_Bounded_Stack bounded_stack);
int ExtendRunRight(int start, int end);
int ExtendRunLeft(int start, int end);
void Merge(void* A, int s0, int s1, int e1);

#endif
