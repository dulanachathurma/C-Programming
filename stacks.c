#include <stdio.h>
#include <stdlib.h>
typedef enum {
    ONE = 1,
    TWO,
    THREE,
    FOUR
} Mynumbers;

typedef enum {
    false,
    true
} Boolean;


typedef struct {
    int top;
    int Ar[20];
} stack;


void createStack(stack *s) {
    s->top = -1;
}

int main() {
    stack s;
    createStack(&s);

    printf("Stack initialized. Top = %d\n", s.top);

    return 0;
}
