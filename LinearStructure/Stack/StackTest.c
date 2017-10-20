//
// Created by luyanfcp on 17-10-21.
//

#include "Stack.h"

int main()
{
    Stack stack = createStack();
    for (int i = 0; i <30 ; ++i) {
        push(stack,i);
    }
    for (int j = 0; j <= stack->top ; ++j) {
        printf("%d, ",stack->base[j]);
    }

}