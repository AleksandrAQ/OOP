#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10
#define init_array(A) __init_array(&A, 10)
#define multiset(A, num, ...) __multiset(A, num, __VA_ARGS__)

typedef int EType;

typedef struct
{
    size_t bufferSize;
    size_t currentSize;
    EType *elements;
} ArrayType;

typedef ArrayType* Array;

void resize(Array A)
{
    size_t newSize = A->bufferSize * 2;
    EType *newElements = (EType *)realloc(A->elements, newSize * sizeof(EType));
    if(newElements == NULL)
    {
        fprintf(stderr, "Can't reallocate memory\n");
        exit(1);
    }
    A->elements = newElements;
    A->bufferSize = newSize;
}

void add(Array A, EType e)
{
    if(A->currentSize >= A->bufferSize)
            resize(A);
    A->elements[A->currentSize++] = e;
}

void set(Array A, int index, EType e)
{
    if(index >= A->currentSize || index < 0)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    A->elements[index] = e;
}

EType get(Array A, int index)
{
    if(index >= A->currentSize || index < 0)
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }
    return A->elements[index];
}

size_t size(Array A)
{
    return A->currentSize;
}

void __init_array(Array *A, int size)
{
    *A = malloc(sizeof(ArrayType));
    if(*A == NULL)
    {
        fprintf(stderr, "Can't allocate memory\n");
        exit(1);
    }

    EType *elements = calloc(size, sizeof(EType));
    if(elements == NULL)
    {
        fprintf(stderr, "Can't allocate memory\n");
        exit(1);
    }
    (*A)->elements = elements;
    (*A)->bufferSize = size;
    (*A)->currentSize = 0;
}

void readInts(Array A, const char *filename)
{
    FILE *fp;
    if(filename == NULL || (fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "readInts: Error: Can't open file %s\n", filename);
        exit(1);
    }
    int value;
    while(fscanf(fp, "%d", &value) == 1)
        add(A, value);
    if (A -> bufferSize > size(A))
    {
        int memory = size(A);
        int *elements = realloc (A -> elements, memory*sizeof(EType)); 
        if (A -> elements == NULL)
        {
            fprintf (stderr, "Can't reallocate memory\n");
            exit(1);
        }
        A->elements = elements;
        A->bufferSize = memory;
    }
    fclose(fp);
}

void print_array(Array A)
{
	int i;
	for(i = 0; i < size(A); i++)
		printf("%d ", get(A,i));
	printf("\n");
}

void _remove(Array A) 
{
    int member = A->currentSize - 1;
    A->currentSize = member;

    if (A->currentSize <= ((A -> bufferSize) / 4))
      {
        size_t newSize = A->bufferSize / 2;
        EType *newElements = (EType *)realloc(A->elements, newSize * sizeof(EType));
        if(newElements == NULL)
        {
            fprintf(stderr, "Can't reallocate memory\n");
            exit(1);
        }
        A->elements = newElements;
        A->bufferSize = newSize;
      }
}

void dyn2arr(Array A, int **B)
{
    *B = malloc(sizeof(int)*size(A));
    //int i=0;
    for(int i= 0; i < size(A); i++)
        (*B)[i] = get(A, i);
}

void arr2dyn(int *B, Array A, int N)
{
    int i=0;
    for(i; i < N; i++)
    {
        //set(A, i, B[i]);
        add(A, B[i]);
    }
}
void SWAP (Array A, int i, int j) 
{
    int memory1, memory2;
    memory1 = get(A, i);
    memory2 = get(A, j);
    set(A, j, memory1);
    set(A, i, memory2);
}
void destroy_array(Array A)
{
    free(A->elements);
}

int main(int argc, char **argv)
{

    char *fname = "numbers.txt";
    Array A;
    init_array(A);
    readInts(A, fname);
    print_array(A);
    _remove(A);
    print_array(A);
    _remove(A);
    print_array(A);
    printf("%d\n", A -> bufferSize);
    int *B;
    dyn2arr(A, &B);
    print_array(A);
    int i=0;
    for(i; i < size(A); i++)
        printf("%d ", B[i]);
    int B[]={1,2,3,4,5,6,7,8,9,10};
    arr2dyn(B, A, 7);
    print_array(A);
    print_array(A);
    SWAP(A,3,4);
    print_array(A);
    destroy_array(A);
    printf("\n%d", size(A));
    printf("%d\n\n", A -> bufferSize);
    printf("%d\n\n", A -> currentSize);
}