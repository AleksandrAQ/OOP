#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef double StackElement;

#define format "%lf\n"

typedef struct
{
    StackElement *elements;
    int top;
    int maxSize;
} Stack;

void StackInit(Stack *S, int maxSize)
{
    StackElement *newElements;
    newElements = malloc(maxSize * sizeof(StackElement)); 
    if(newElements == NULL)
    {
        fprintf(stderr, "Error: Can't allocate memory\n");
        exit(3);
    }
    S->elements = newElements;
    S->maxSize = maxSize;
    S->top = -1;
}

void StackDestroy(Stack *S)
{
    free(S->elements);
    S->elements = NULL;
    S->maxSize = 0;
    S->top = -1;
}

bool StackIsFull(Stack *S)
{
    return S->top >= S->maxSize-1;
}

bool StackIsEmty(Stack *S)
{
    return S->top < 0;
}

void StackPush(Stack *S, StackElement x)
{
    if(StackIsFull(S))
    {
        fprintf(stderr, "Stack overflow");
        exit(1);
    }
    S->elements[++S->top]=x;
}

void StackPrint(Stack *S)
{
    int i;
    for(i = 0; i <= S->top; i++)
        printf(format, S->elements[i]);
}

double evaluate(char *expr)
{

}

int main()
{
    Stack S;
    StackInit(&S, 5);

    StackPush(&S, 7);
    StackPush(&S, 11);
    StackPush(&S, 100);

    StackPrint(&S);

    printf(format, S.elements[2]); 

    return 0;
}
