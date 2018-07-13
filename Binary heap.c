#include <stdio.h>
#include <stdbool.h>

typedef int EType;

bool max_heap(EType a, EType b)
{
    return a>b? true : false;
}

bool min_heap(EType a, EType b)
{
    return a<b? true : false;
}

/*void swap(int *a, int i, int j) 
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}*/

void heapify(Array A, int heap_size, int i, bool(*cmp)(EType, EType))
{
    int l = left(i);
    int r = right(i);
    int current = i;
    if(l < heap_size && cmp(get(A, l), get(A, current))
       current = l;
    if(r < heap_size && cmp(get(A, l), get(A, current))
       current = r;
    if(current != i)
    {
        swap(A, i, current)
        heapify(A, heap_size, curent, cmp)
    }
}

void heap_build(Array A, bool(*cmp)(EType, EType))
int i;
{
    for(i = size(A)/2-1; i>=0; i--)
        heapify(A, size(A), i, cmp);
}

void heap_insert(Array A, EType k, bool(*cmp)(EType,Etype))
{
    add(A, k);
    heap_shift_up(A, size(A)-1, cmp);
}

void heap_shift_up(Array A, int i, bool (*cmp)(Etype,EType))
{
    while(i>0 && cmp(get(A, i), get(A, parent(i))))
    {
        swap(A, i, parent(i));
        i = parent(i);
    }
}

Etype heap_get(Array A)
{
    return get(A, 0)
}

Etype heap_extract(Array A, bool(*cmp)(EType,EType))
{
    if(size(A)==0)
    {
        printf(stderr, "Heap is empty\n");
        exit(1);
    }
    EType e = get(A, 0)
    set(A, 0, get(A, size(A)-1));
    remove(A);
    decipify(A, size(A), 0, cmp);
    return e;
}

void heap_sort(Array A, bool(*cmp)(EType,EType))
{
    for(i = size(A)-1; i > 0; i--)
    {
        swap(A, 0, i);
        heapify(A, i, 0, cmp);
    }
}

int main(void)
{
    heapify(A, size(A), 1, max_heap);
}
