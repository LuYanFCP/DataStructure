//
// Created by luyanfcp on 17-10-20.
//
#include "Stack.h"

Stack createStack()
{
    Stack newStack = (Stack)malloc(sizeof(struct sqStack));
    newStack->base = malloc(DEFAULT_VOLUME*sizeof(AnyType));
    newStack->stackSize = DEFAULT_VOLUME;
    return newStack;
}
bool destroyStack(Stack stack)
{
    free(stack->base);
    free(stack);
    return true;
}
bool isEmpty(Stack stack)
{
    // 判断栈顶是否是NULL
    return (bool) stack->base[stack->top];
};
int stackLength(Stack stack)
{
    return stack->top+1;
}
bool push(Stack stack, AnyType x)
{
    //如果 没有空间
    if (stack->top == (stack->stackSize-1))
        stack->base = realloc(stack->base, (size_t) (stack->stackSize + INCREMENT));
    stack->base[++stack->top] = x;
    return true;

}
AnyType top(Stack stack)
{
    return *(stack->base + stack->top);
}
AnyType pop(Stack stack)
{
    return *(stack->base + stack->top--);
}